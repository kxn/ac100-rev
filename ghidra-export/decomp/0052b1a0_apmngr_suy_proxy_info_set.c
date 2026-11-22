// func apmngr_suy_proxy_info_set @ 0052b1a0 size=296

undefined4
apmngr_suy_proxy_info_set(undefined4 param_1,uint param_2,int param_3,char *param_4,char *param_5)

{
  size_t sVar1;
  char *__dest;
  
  if ((int)param_2 < 1) {
    param_2 = g_sub_proxy_url_max_len;
  }
  if (param_3 < 1) {
    param_3 = g_sub_proxy_url_port;
  }
  g_sub_proxy_url_max_len = param_2;
  g_sub_proxy_url_port = param_3;
  g_support_sub_sub_proxy = param_1;
  if ((((param_4 != (char *)0x0) && (sVar1 = strlen(param_4), 0 < (int)sVar1)) && (sVar1 < param_2))
     && (__dest = (char *)FUN_00408450(sVar1 + 1,0x2cb), g_sub_proxy_url_uri = __dest,
        __dest != (char *)0x0)) {
    memset(__dest,0,sVar1 + 1);
    strncpy(__dest,param_4,sVar1);
  }
  if (param_5 != (char *)0x0) {
    sVar1 = strlen(param_5);
    if ((0 < (int)sVar1) && (sVar1 < 0x10)) {
      g_sub_proxy_protocol = 0;
      DAT_007c5820 = 0;
      DAT_007c5824 = 0;
      DAT_007c5828 = 0;
      strncpy((char *)&g_sub_proxy_protocol,param_5,0x10);
    }
  }
  return 0;
}

