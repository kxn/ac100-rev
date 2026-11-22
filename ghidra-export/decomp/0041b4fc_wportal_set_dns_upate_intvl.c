// func wportal_set_dns_upate_intvl @ 0041b4fc size=16

undefined4 wportal_set_dns_upate_intvl(undefined4 param_1)

{
  g_cloud_host_dns_upate_intvl = param_1;
  return 0;
}

