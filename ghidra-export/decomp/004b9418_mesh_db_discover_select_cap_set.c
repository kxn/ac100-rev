// func mesh_db_discover_select_cap_set @ 004b9418 size=272

undefined4 mesh_db_discover_select_cap_set(int param_1,short param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Illegal input\n","mesh_db_discover_select_cap_set",0x520);
    }
  }
  else {
    FUN_004082d0(DAT_00767eb4,0xffffffff);
    iVar2 = FUN_00407fa0(DAT_00767f68,param_1);
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
      FUN_00407f30(DAT_00767eb4);
    }
    else {
      iVar2 = FUN_004081b0(iVar2 + 0x58);
      if (iVar2 == 0) {
        uVar3 = 0xffffffff;
      }
      else {
        cVar1 = *(char *)(iVar2 + 0x10);
        while (cVar1 != '\x01') {
          if (*(short *)(iVar2 + 0xc) == param_2) {
            *(bool *)(iVar2 + 0x18) = param_3 != 0;
            uVar3 = 0;
            goto LAB_004b94ac;
          }
          iVar2 = FUN_00408680(iVar2);
          if (iVar2 == 0) {
            uVar3 = 0xffffffff;
            goto LAB_004b94ac;
          }
          cVar1 = *(char *)(iVar2 + 0x10);
        }
        uVar3 = 0xffffffff;
      }
LAB_004b94ac:
      FUN_00407f30(DAT_00767eb4);
    }
  }
  return uVar3;
}

