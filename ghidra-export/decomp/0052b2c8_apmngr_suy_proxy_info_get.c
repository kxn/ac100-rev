// func apmngr_suy_proxy_info_get @ 0052b2c8 size=204

undefined4
apmngr_suy_proxy_info_get
          (undefined4 *param_1,uint *param_2,undefined4 *param_3,char *param_4,uint param_5,
          char *param_6,uint param_7)

{
  size_t sVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = g_support_sub_sub_proxy;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = g_sub_proxy_url_max_len;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = g_sub_proxy_url_port;
  }
  if ((param_4 != (char *)0x0) && (g_sub_proxy_url_max_len <= param_5)) {
    strncpy(param_4,g_sub_proxy_url_uri,param_5);
  }
  if ((param_6 != (char *)0x0) && (sVar1 = strlen((char *)&g_sub_proxy_protocol), sVar1 < param_7))
  {
    strncpy(param_6,(char *)&g_sub_proxy_protocol,param_7);
  }
  return 0;
}

