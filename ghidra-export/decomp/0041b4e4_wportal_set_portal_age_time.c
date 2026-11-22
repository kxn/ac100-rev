// func wportal_set_portal_age_time @ 0041b4e4 size=24

undefined4 wportal_set_portal_age_time(int param_1)

{
  g_portal_age_time = param_1 * 0x3c;
  return 0;
}

