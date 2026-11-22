// func arp_defend_str2mac @ 004797b0 size=228

undefined4 arp_defend_str2mac(char *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [8];
  
  if ((param_1 == (char *)0x0) || (param_2 == (undefined1 *)0x0)) {
    uVar3 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n","arp_defend_str2mac",0x32c);
    }
  }
  else {
    uVar3 = 0;
    if (*param_1 != '\0') {
      sscanf(param_1,"%2X-%2X-%2X-%2X-%2X-%2X",&local_28,auStack_24,auStack_20,auStack_1c,auStack_18
             ,auStack_14);
      iVar1 = 0;
      do {
        puVar2 = (undefined4 *)((int)&local_28 + iVar1);
        iVar1 = iVar1 + 4;
        *param_2 = (char)*puVar2;
        param_2 = param_2 + 1;
      } while (iVar1 != 0x18);
      uVar3 = 0;
    }
  }
  return uVar3;
}

