// func _apdb_md5_calc @ 005fc2e4 size=328

void _apdb_md5_calc(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_80 [108];
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : enter _apdb_md5_calc\n","_apdb_md5_calc",0x3c0);
  }
  if (param_2 == 0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : the apdb is null\n","_apdb_md5_calc",0x3c7);
    }
  }
  else {
    FUN_00408590(auStack_80);
    FUN_00408670(auStack_80,param_2 + 0x10,0x154);
    FUN_00408670(auStack_80,*(undefined4 *)(param_2 + 0x164),0x28);
    iVar1 = *(int *)(*(int *)(param_2 + 0x164) + 0x28);
    if (iVar1 == 0) {
      iVar1 = *(int *)(*(int *)(param_2 + 0x164) + 0x2c);
    }
    else {
      do {
        FUN_00408670(auStack_80,iVar1,0x110);
        iVar1 = *(int *)(iVar1 + 0x110);
      } while (iVar1 != 0);
      iVar1 = *(int *)(*(int *)(param_2 + 0x164) + 0x2c);
    }
    if (iVar1 != 0) {
      FUN_00408670(auStack_80,iVar1,8);
    }
    iVar1 = *(int *)(param_2 + 0x164);
    if (*(int *)(iVar1 + 0x30) != 0) {
      FUN_00408670(auStack_80,*(int *)(iVar1 + 0x30),0xc3);
      iVar1 = *(int *)(param_2 + 0x164);
    }
    if (*(int *)(iVar1 + 0x34) != 0) {
      FUN_00408670(auStack_80,*(int *)(iVar1 + 0x34),0x1fc);
    }
    FUN_00407e90(param_1,auStack_80);
  }
  return;
}

