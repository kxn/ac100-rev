// func rrm_ap_collect_info_set @ 004ae5bc size=1

void rrm_ap_collect_info_set(short param_1,short param_2,char param_3,short param_4)

{
  if (param_1 == 0) {
    param_1 = DAT_0073190e;
  }
  DAT_0073190e = param_1;
  if (param_2 == 0) {
    param_2 = DAT_0073190c;
  }
  DAT_0073190c = param_2;
  if (param_4 == 0) {
    param_4 = DAT_00731910;
  }
  DAT_00731910 = param_4;
  if (param_3 == '\0') {
    param_3 = DAT_0073190a;
  }
  DAT_0073190a = param_3;
  return;
}

