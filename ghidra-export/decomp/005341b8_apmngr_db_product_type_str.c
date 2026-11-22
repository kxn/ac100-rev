// func apmngr_db_product_type_str @ 005341b8 size=44

char * apmngr_db_product_type_str(uint param_1)

{
  if (param_1 < 4) {
    return (&PTR_s_AP_006c9cd8)[param_1];
  }
  return "Device";
}

