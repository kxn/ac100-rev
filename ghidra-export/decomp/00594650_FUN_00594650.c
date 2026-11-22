// func FUN_00594650 @ 00594650 size=548

undefined4 FUN_00594650(char *param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0xffffffff;
  if (((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) && (param_3 != 0)) {
    sVar2 = strlen(param_1);
    uVar1 = FUN_00407fe0(param_3);
    snprintf(param_1 + sVar2,0x200 - sVar2,"\"%u[",uVar1);
    for (iVar3 = FUN_004081b0(param_3); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
      sVar2 = strlen(param_1);
      snprintf(param_1 + sVar2,0x200 - sVar2,"%u,",(uint)*(ushort *)(iVar3 + 0xc));
      iVar4 = FUN_00407fe0(iVar3 + 0x10);
      if (iVar4 != 0) {
        sVar2 = strlen(param_2);
        snprintf(param_2 + sVar2,0x200 - sVar2,"%u[",(uint)*(ushort *)(iVar3 + 0xc));
        for (iVar4 = FUN_004081b0(iVar3 + 0x10); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
          sVar2 = strlen(param_2);
          snprintf(param_2 + sVar2,0x200 - sVar2,"%u,",(uint)*(ushort *)(iVar4 + 0xc));
        }
        sVar2 = strlen(param_2);
        snprintf(param_2 + (sVar2 - 1),0x201 - sVar2,"],");
      }
    }
    if (snapshot_store_debug_switch != 0) {
      printf("[SNAPSHOT_STORE_DEBUG]%s()/%d sub msg_ele %s\n","msg_ele_format_output",0x3c,param_2);
    }
    if (snapshot_store_debug_switch != 0) {
      printf("[SNAPSHOT_STORE_DEBUG]%s()/%d msg_ele %s\n","msg_ele_format_output",0x3d,param_1);
    }
    sVar2 = strlen(param_1);
    snprintf(param_1 + (sVar2 - 1),0x201 - sVar2,"]\",");
    uVar1 = 0;
  }
  return uVar1;
}

