// func cw_sta_assoc_req_subelement_add @ 005c2198 size=608

undefined4 cw_sta_assoc_req_subelement_add(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *__s;
  uint *puVar2;
  undefined2 uVar5;
  int *piVar3;
  void *__src;
  uint uVar4;
  char *__format;
  undefined4 uVar6;
  
  if ((((param_1 == 0) || (param_2 < 0)) || (1 < param_2)) || (param_3 == 0)) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d Input error\n";
    uVar6 = 0x286;
LAB_005c2220:
    printf(__format,"cw_sta_assoc_req_subelement_add",uVar6);
    return 0xffffffff;
  }
  __s = (void *)FUN_00408450(0x14,0x28a);
  if (__s == (void *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d out of memory\n";
    uVar6 = 0x28d;
    goto LAB_005c2220;
  }
  memset(__s,0,0x14);
  *(short *)((int)__s + 0xc) = (short)param_2;
  if (param_2 == 1) {
    piVar3 = (int *)cw_protocol_clone(param_3,0x10);
    *(int **)((int)__s + 0x10) = piVar3;
    if (piVar3 != (int *)0x0) {
      if (*piVar3 == 0) {
        uVar5 = (undefined2)*piVar3;
LAB_005c2290:
        *(undefined2 *)((int)__s + 0xe) = uVar5;
        *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 4 + (uint)*(ushort *)((int)__s + 0xe)
        ;
        FUN_004086b0(param_1 + 0x14,__s);
        return 0;
      }
      __src = (void *)cw_protocol_clone(param_3 + 4,0xc);
      if (__src != (void *)0x0) {
        memcpy(piVar3 + 1,__src,0xc);
        uVar5 = (undefined2)*piVar3;
        goto LAB_005c2290;
      }
LAB_005c22d0:
      iVar1 = *(int *)((int)__s + 0x10);
      goto LAB_005c22d4;
    }
    if (capwap_err_switch == 0) {
      iVar1 = *(int *)((int)__s + 0x10);
      goto LAB_005c22d4;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = *(int *)((int)__s + 0x10);
      goto LAB_005c22d4;
    }
    uVar6 = 0x2ab;
  }
  else {
    puVar2 = (uint *)cw_protocol_clone(param_3,8);
    *(uint **)((int)__s + 0x10) = puVar2;
    if (puVar2 != (uint *)0x0) {
      puVar2[1] = 0;
      if (*puVar2 != 0) {
        uVar4 = cw_protocol_clone(*(undefined4 *)(param_3 + 4),*puVar2 & 0xffff);
        puVar2[1] = uVar4;
      }
      uVar5 = (undefined2)*puVar2;
      goto LAB_005c2290;
    }
    if (capwap_err_switch == 0) goto LAB_005c22d0;
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = *(int *)((int)__s + 0x10);
      goto LAB_005c22d4;
    }
    uVar6 = 0x299;
  }
  printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_sta_assoc_req_subelement_add",uVar6);
  iVar1 = *(int *)((int)__s + 0x10);
LAB_005c22d4:
  if (iVar1 != 0) {
    FUN_00407df0();
    *(undefined4 *)((int)__s + 0x10) = 0;
  }
  FUN_00407df0(__s);
  return 0xffffffff;
}

