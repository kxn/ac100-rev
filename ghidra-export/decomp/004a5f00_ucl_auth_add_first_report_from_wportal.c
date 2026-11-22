// func ucl_auth_add_first_report_from_wportal @ 004a5f00 size=32

void ucl_auth_add_first_report_from_wportal(void)

{
  wportal_db_aut_foreach(ucl_auth_add_first_report_cb,0);
  return;
}

