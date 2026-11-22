// func wportal_set_mode @ 0041b4ac size=16

undefined4 wportal_set_mode(undefined4 param_1)

{
  g_portal_auth_mode = param_1;
  return 0;
}

