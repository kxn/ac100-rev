import unittest
from audit_roaming_candidates import audit, utc_sort_key

class CandidateAudit(unittest.TestCase):
    def test_nanosecond_sort_does_not_treat_short_fraction_as_later(self):
        a={'time':'2026-01-01T00:00:00.1Z'}
        b={'time':'2026-01-01T00:00:00.100000001Z'}
        self.assertLess(utc_sort_key(a),utc_sort_key(b))

    def test_run_scope_raw_reports_and_partial_capture(self):
        events=[
            {'event':'ap.radio_statistics','ap_id':'source','vaps':[{'BSSID':[0,0,0,0,0,1]}]},
            {'event':'ap.radio_statistics','ap_id':'other','vaps':[{'BSSID':[0,0,0,0,0,2]}]},
            {'event':'roaming.station_report','run_id':'one','ap_id':'source','client':'client','neighbors':[{'BSSID':[0,0,0,0,0,1]}]},
            {'event':'roaming.decision','run_id':'one','decision_id':1,'ap_id':'source','client':'client','radio':1,'candidate_count':1},
            {'event':'roaming.candidate_input','run_id':'one','decision_id':1,'candidate':{'ap_id':'source','radio':2}},
            {'event':'roaming.station_report','run_id':'two','ap_id':'source','client':'client','neighbors':[{'BSSID':[0,0,0,0,0,2]}]},
            {'event':'roaming.decision','run_id':'two','decision_id':1,'ap_id':'source','client':'client','radio':1,'candidate_count':1},
            {'event':'roaming.candidate_input','run_id':'two','decision_id':1,'candidate':{'ap_id':'other','radio':1}},
            {'event':'roaming.decision','run_id':'two','decision_id':2,'ap_id':'source','client':'client','radio':1,'candidate_count':2},
            {'event':'roaming.candidate_input','run_id':'two','decision_id':2,'candidate':{'ap_id':'source','radio':2}},
        ]
        r=audit(events)['summary']
        self.assertEqual(r['decisions'],3)
        self.assertEqual(r['source_ap_only'],1)
        self.assertEqual(r['source_only:raw_source_ap_only'],1)
        self.assertEqual(r['source_only:other_radio'],1)
        self.assertEqual(r['includes_other_ap'],1)
        self.assertEqual(r['partial_input_logs'],1)

if __name__=='__main__':unittest.main()
