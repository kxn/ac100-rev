// func uac_ipaddr_is_not_empty @ 0051ab84 size=192

bool uac_ipaddr_is_not_empty(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  int local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  param_1 = param_1 >> 0x18;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if (param_1 < 3) {
    bVar2 = false;
    if ((param_1 != 0) && (bVar2 = param_2 != 0, param_1 != 1)) {
      iVar1 = memcmp(&local_res4,&local_18,0x10);
      bVar2 = iVar1 != 0;
    }
  }
  else {
    bVar2 = false;
    if (uac_ip_err_switch != 0) {
      printf("[UAC_IP_ERROR]%s()/line %d : Invalid params.\n","uac_ipaddr_is_not_empty",0xa9);
    }
  }
  return bVar2;
}

