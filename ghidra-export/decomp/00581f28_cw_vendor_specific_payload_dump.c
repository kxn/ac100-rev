// func cw_vendor_specific_payload_dump @ 00581f28 size=464

undefined4 cw_vendor_specific_payload_dump(int param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  puVar7 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Vendor Specific Payload \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Vendor Specific Payload (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x%04x... \r\n",*puVar7,(uint)*(ushort *)(puVar7 + 1));
  printf("\t\t\tVendor Identifier: Unknown (%d) \r\n",*puVar7);
  printf("\t\t\tVendor Element ID: %d \r\n",(uint)*(ushort *)(puVar7 + 1));
  iVar2 = FUN_004081b0(puVar7 + 2);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    puVar3 = (ushort *)cw_msg_ele_priv_mngr_get(*(undefined2 *)(iVar2 + 0xc));
    if (puVar3 == (ushort *)0x0) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
             "cw_msg_eles_priv_dump",0x189,(uint)*(ushort *)(iVar2 + 0xc));
      return 0xffffffff;
    }
    if (*(int *)(iVar2 + 0x10) == 0) break;
    iVar4 = (**(code **)(puVar3 + 0xe))(iVar2);
    if (iVar4 == -1) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar1 = *puVar3;
      uVar6 = *(undefined4 *)(puVar3 + 2);
      __format = "[CW_ERROR]%32s():%4d failed to dump %s(%d)\n";
      uVar5 = 0x19e;
      goto LAB_005820a8;
    }
    iVar2 = FUN_00408680(iVar2);
  }
  if (capwap_err_switch == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uVar1 = *puVar3;
  uVar6 = *(undefined4 *)(puVar3 + 2);
  __format = "[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value\n";
  uVar5 = 0x197;
LAB_005820a8:
  printf(__format,"cw_msg_eles_priv_dump",uVar5,uVar6,(uint)uVar1);
  return 0xffffffff;
}

