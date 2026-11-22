// func uac_ipaddr_cmp @ 0051aa18 size=132

bool uac_ipaddr_cmp(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,uint param_6,int param_7)

{
  bool bVar2;
  int iVar1;
  int local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  param_6 = param_6 >> 0x18;
  bVar2 = false;
  if (param_6 == param_1 >> 0x18) {
    if (param_6 == 1) {
      bVar2 = param_2 == param_7;
    }
    else if (param_6 == 2) {
      local_res4 = param_2;
      local_res8 = param_3;
      local_resc = param_4;
      iVar1 = memcmp(&local_res4,&param_7,0x10);
      bVar2 = iVar1 == 0;
    }
  }
  return bVar2;
}

