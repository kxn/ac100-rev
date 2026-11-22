// func apmngr_db_product_type_str_by_ap_role @ 005341e4 size=44

char * apmngr_db_product_type_str_by_ap_role(uint param_1)

{
  if (param_1 < 9) {
    return (&PTR_s_AP_006c9ce8)[param_1];
  }
  return "Device";
}

