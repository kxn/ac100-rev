// func serv_msg_mngr_register @ 00599c78 size=268

undefined4 serv_msg_mngr_register(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  iVar2 = serv_msg_mngr_get();
  if (iVar2 != 0) {
    iVar3 = FUN_00408450(0x14,0x2c4);
    if (iVar3 == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d out of memory\n","serv_msg_mngr_register",0x2c6);
      }
    }
    else {
      *(undefined2 *)(iVar3 + 0xc) = param_2;
      *(undefined4 *)(iVar3 + 0x10) = param_3;
      iVar4 = FUN_004081b0(iVar2 + 4);
      if (iVar4 == 0) {
LAB_00599d04:
        uVar5 = 0;
        FUN_004086b0(iVar2 + 4,iVar3);
      }
      else {
        uVar1 = *(ushort *)(iVar3 + 0xc);
        while (uVar1 <= *(ushort *)(iVar4 + 0xc)) {
          iVar4 = FUN_00408680();
          if (iVar4 == 0) goto LAB_00599d04;
          uVar1 = *(ushort *)(iVar3 + 0xc);
        }
        FUN_00408170(iVar4,iVar3);
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}

