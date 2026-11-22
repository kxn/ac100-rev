// func _uac_arp_defend_ap_jcs_set @ 00474b04 size=448

void _uac_arp_defend_ap_jcs_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar1 = json_object_object_get(param_1,"operation");
  if (iVar1 == 0) {
    if (arp_defend_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d %s not found!\n","_uac_arp_defend_ap_jcs_set",0x41a,
           "operation");
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    uVar4 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 != 2) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_arp_defend_ap_jcs_set",0x41b);
      }
      goto LAB_00474b8c;
    }
    uVar5 = json_object_get_double(iVar1);
    uVar4 = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
  }
  if (uVar4 < 6) {
                    /* WARNING: Could not recover jumptable at 0x00474c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&PTR_LAB_00690870)[uVar4])();
    return;
  }
LAB_00474b8c:
  if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_ERROR]%s()/%d Invalid operaiton.\n","_uac_arp_defend_ap_jcs_set",0x42b);
  }
  uVar3 = json_object_new_int(0xffffffff);
  json_object_object_add(param_2,"result",uVar3);
  return;
}

