// func capwap_parsed_packet_dump @ 00587598 size=740

undefined4 capwap_parsed_packet_dump(int param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  
  if (param_1 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d input parameter is wrong\n";
    uVar4 = 0x73f;
  }
  else {
    puts("******************* dump capwap message start *************************** \r");
    puts("Control And Provisioning of Wireless Access Points \r");
    iVar1 = cw_header_dump(param_1);
    if (iVar1 == -1) {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_ERROR]%32s():%4d failed to dump capwap header\n";
      uVar4 = 0x749;
    }
    else {
      iVar1 = cw_control_header_dump(param_1 + 0x10);
      if (iVar1 != -1) {
        puts("\tMessage Element\r");
        iVar1 = FUN_004081b0(param_1 + 0x1c);
        while( true ) {
          if (iVar1 == 0) {
            puts("******************* dump capwap message end *************************** \r");
            if (capwap_debug_switch == 0) {
              return 0;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 != 0) {
              uVar4 = cw_control_msg_name(*(undefined4 *)(param_1 + 0x10));
              printf("[CW_DEBUG]%32s():%4d success to dump %s(%d)\n","capwap_parsed_packet_dump",
                     0x75c,uVar4,*(undefined4 *)(param_1 + 0x10));
              return 0;
            }
            return 0;
          }
          puVar2 = (ushort *)cw_msg_ele_mngr_get(*(undefined2 *)(iVar1 + 0xc));
          if (puVar2 == (ushort *)0x0) break;
          if (*(int *)(iVar1 + 0x10) == 0) {
            if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[CW_ERROR]%32s():%4d %s(%d) doesn\'t have value\n","cw_msg_eles_dump",0x17a,
                     *(undefined4 *)(puVar2 + 2),(uint)*puVar2);
            }
            goto LAB_00587800;
          }
          iVar3 = (**(code **)(puVar2 + 0xe))(iVar1);
          if (((iVar3 == -1) && (capwap_err_switch != 0)) &&
             (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[CW_ERROR]%32s():%4d failed to dump %s(%d)\n","cw_msg_eles_dump",0x181,
                   *(undefined4 *)(puVar2 + 2),(uint)*puVar2);
          }
          iVar1 = FUN_00408680(iVar1);
        }
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                 "cw_msg_eles_dump",0x16c,(uint)*(ushort *)(iVar1 + 0xc));
        }
LAB_00587800:
        puts("failed to dump capwap message element\r");
        return 0xffffffff;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_ERROR]%32s():%4d failed to dump capwap control header\n";
      uVar4 = 0x750;
    }
  }
  printf(__format,"capwap_parsed_packet_dump",uVar4);
  return 0xffffffff;
}

