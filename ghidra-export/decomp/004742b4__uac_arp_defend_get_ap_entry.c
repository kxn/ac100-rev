// func _uac_arp_defend_get_ap_entry @ 004742b4 size=748

undefined4 _uac_arp_defend_get_ap_entry(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char acStack_388 [256];
  char acStack_288 [256];
  undefined1 auStack_188 [218];
  char acStack_ae [65];
  char local_6d [81];
  
  memset(acStack_288,0,0x100);
  memset(auStack_188,0,0x168);
  if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_get_ap_entry begins, ap_id:%d\n",
           "_uac_arp_defend_get_ap_entry",0x11e,*param_2);
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d no memory!\n";
    uVar5 = 0x123;
  }
  else {
    snprintf(acStack_288,0x100,"%d",*param_2);
    uVar2 = json_object_new_string(acStack_288);
    json_object_object_add(iVar1,"ap_id",uVar2);
    uVar2 = json_object_new_string(param_1 + 0x4e);
    json_object_object_add(iVar1,"name",uVar2);
    if (*(int *)(param_1 + 0xc) == 0) {
      pcVar4 = "template";
    }
    else {
      pcVar4 = "ap";
    }
    uVar2 = json_object_new_string(pcVar4);
    json_object_object_add(iVar1,"ap_type",uVar2);
    iVar3 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_188);
    if (iVar3 == 0) {
      pcVar4 = local_6d;
      if (local_6d[0] == '\0') {
        pcVar4 = acStack_ae;
      }
    }
    else {
      pcVar4 = "";
    }
    snprintf(acStack_288,0x100,"%s",pcVar4);
    uVar2 = json_object_new_string(acStack_288);
    json_object_object_add(iVar1,"model",uVar2);
    arp_defend_mac2str(param_1 + 0x48,acStack_288,0x100);
    uVar2 = json_object_new_string(acStack_288);
    json_object_object_add(iVar1,"mac",uVar2);
    if (*(char *)(param_2 + 1) == '\x01') {
      pcVar4 = "Led on";
    }
    else {
      pcVar4 = "Led off";
    }
    uVar2 = json_object_new_string(pcVar4 + 4);
    json_object_object_add(iVar1,"enable",uVar2);
    memset(acStack_388,0,0x100);
    snprintf(acStack_388,0x100,"%d",param_2[2]);
    uVar2 = json_object_new_string(acStack_388);
    json_object_object_add(iVar1,"bind_cnt",uVar2);
    json_object_array_add(param_3,iVar1);
    uVar2 = 0;
    if (arp_defend_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = "[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_get_ap_entry() finishes\n";
    uVar5 = 0x13e;
  }
  printf(pcVar4,"_uac_arp_defend_get_ap_entry",uVar5);
  return uVar2;
}

