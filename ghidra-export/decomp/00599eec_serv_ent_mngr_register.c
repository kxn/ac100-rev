// func serv_ent_mngr_register @ 00599eec size=296

undefined4 serv_ent_mngr_register(uint param_1,undefined2 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  if ((((param_1 & 0xffff) < 4) && (param_3 != 0)) &&
     (iVar4 = (&g_serv_ent_mngr)[param_1 & 0xffff], iVar4 != 0)) {
    iVar2 = FUN_00408450(0x14,0x366);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[CW_ERROR]%32s():%4d out of memory\n","serv_ent_mngr_register",0x368);
      }
    }
    else {
      iVar4 = iVar4 + 4;
      *(undefined2 *)(iVar2 + 0xc) = param_2;
      *(int *)(iVar2 + 0x10) = param_3;
      iVar3 = FUN_004081b0(iVar4);
      if (iVar3 == 0) {
LAB_00599f94:
        uVar5 = 0;
        FUN_004086b0(iVar4,iVar2);
      }
      else {
        uVar1 = *(ushort *)(iVar2 + 0xc);
        while (uVar1 <= *(ushort *)(iVar3 + 0xc)) {
          iVar3 = FUN_00408680();
          if (iVar3 == 0) goto LAB_00599f94;
          uVar1 = *(ushort *)(iVar2 + 0xc);
        }
        FUN_00408170(iVar3,iVar2);
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}

