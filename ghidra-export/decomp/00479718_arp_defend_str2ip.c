// func arp_defend_str2ip @ 00479718 size=152

void * arp_defend_str2ip(void *param_1,int param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (param_2 == 0) {
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(0), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n","arp_defend_str2ip",0x31e);
    }
  }
  else {
    FUN_0051a7a8(param_2,&local_20);
  }
  memcpy(param_1,&local_20,0x14);
  return param_1;
}

