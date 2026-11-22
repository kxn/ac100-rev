// func _mesh_collect_pair_list @ 004bc18c size=328

undefined4 _mesh_collect_pair_list(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = FUN_004081b0(param_1 + 0x58);
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + 0x18);
    while (cVar1 == '\0') {
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) goto LAB_004bc1dc;
      cVar1 = *(char *)(iVar2 + 0x18);
    }
    uVar4 = (uint)*(ushort *)(iVar2 + 0xc);
    if (uVar4 != 0xffff) goto LAB_004bc200;
  }
LAB_004bc1dc:
  iVar2 = FUN_004081b0(param_1 + 0x58);
  uVar4 = 0xffff;
  if (iVar2 != 0) {
    uVar4 = (uint)*(ushort *)(iVar2 + 0xc);
  }
LAB_004bc200:
  uVar3 = 0;
  if ((*(int *)(param_1 + 100) == 0) && (uVar4 != 0xffff)) {
    iVar2 = *(int *)(param_2 + 0xc) + uVar4 * 0x140;
    if (*(int *)(iVar2 + 0x10) < 0x32) {
      if (*(int *)(iVar2 + 0x10) == 0) {
        FUN_004086b0(param_2,iVar2);
        *(uint *)(iVar2 + 0xc) = uVar4;
      }
      memcpy((void *)(iVar2 + 0x14 + *(int *)(iVar2 + 0x10) * 6),(void *)(param_1 + 0xc),6);
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
      uVar3 = 0;
    }
    else {
      uVar3 = 2;
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d Re count exceeded\n","_mesh_collect_pair_list",0x624);
      }
    }
  }
  return uVar3;
}

