// func uac_ipaddr_convert_binary2str @ 0051a8d8 size=320

char * uac_ipaddr_convert_binary2str
                 (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,char *param_6,size_t param_7,char *param_8)

{
  char local_res0;
  uint local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if ((param_6 == (char *)0x0) || ((int)param_7 < 0x28)) {
    param_6 = (char *)0x0;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","uac_ipaddr_convert_binary2str",100,
           "ip_str != NULL && str_len >= UAC_IPV6_ADDR_STR_LEN");
  }
  else {
    memset(param_6,0,param_7);
    local_res0 = (char)((uint)param_1 >> 0x18);
    if (local_res0 == '\x01') {
      snprintf(param_6,param_7,"%d.%d.%d.%d",local_res4 >> 0x18,(local_res4 << 8) >> 0x18,
               (local_res4 << 0x10) >> 0x18,local_res4 & 0xff);
    }
    else if (local_res0 == '\x02') {
      inet_ntop(10,&local_res4,param_6,param_7);
    }
    else if (param_8 != (char *)0x0) {
      strncpy(param_6,param_8,param_7 - 1);
    }
  }
  return param_6;
}

