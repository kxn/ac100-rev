// func cw_sta_assoc_rslt_subelement_add @ 005c3cc4 size=680

undefined4 cw_sta_assoc_rslt_subelement_add(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *__s;
  uint *puVar2;
  uint uVar3;
  char *__format;
  undefined4 uVar4;
  
  if ((((param_1 == 0) || (param_2 < 0)) || (2 < param_2)) || ((param_3 == 0 && (param_2 != 2)))) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d Input error\n";
    uVar4 = 0x28b;
LAB_005c3dd8:
    printf(__format,"cw_sta_assoc_rslt_subelement_add",uVar4);
    return 0xffffffff;
  }
  __s = (void *)FUN_00408450(0x14,0x28f);
  if (__s == (void *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d out of memory\n";
    uVar4 = 0x292;
    goto LAB_005c3dd8;
  }
  memset(__s,0,0x14);
  *(short *)((int)__s + 0xc) = (short)param_2;
  if (param_2 == 1) {
    puVar2 = (uint *)cw_protocol_clone(param_3,8);
    *(uint **)((int)__s + 0x10) = puVar2;
    if (puVar2 == (uint *)0x0) {
      if (capwap_err_switch == 0) {
        iVar1 = *(int *)((int)__s + 0x10);
        goto LAB_005c3e44;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        iVar1 = *(int *)((int)__s + 0x10);
        goto LAB_005c3e44;
      }
      uVar4 = 0x2a9;
LAB_005c3f34:
      printf("[CW_ERROR]%32s():%4d Malloc failed\n","cw_sta_assoc_rslt_subelement_add",uVar4);
      iVar1 = *(int *)((int)__s + 0x10);
LAB_005c3e44:
      if (iVar1 != 0) {
        FUN_00407df0();
        *(undefined4 *)((int)__s + 0x10) = 0;
      }
      FUN_00407df0(__s);
      return 0xffffffff;
    }
    puVar2[1] = 0;
    if (*puVar2 == 0) {
      *(short *)((int)__s + 0xe) = (short)*puVar2;
    }
    else {
      uVar3 = cw_protocol_clone(*(undefined4 *)(param_3 + 4),*puVar2 & 0xffff);
      puVar2[1] = uVar3;
      *(short *)((int)__s + 0xe) = (short)*puVar2;
    }
  }
  else if (param_2 == 2) {
    if (*(short *)((int)__s + 0xe) != 0) {
      if (capwap_warning_switch == 0) {
        iVar1 = *(int *)(param_1 + 0x10);
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_1 + 0x10);
        }
        else {
          printf("[CW_WARNING]%32s():%4d Uncorrect sub ele len(%d)\n",
                 "cw_sta_assoc_rslt_subelement_add",0x2b9,(uint)*(ushort *)((int)__s + 0xe));
          iVar1 = *(int *)(param_1 + 0x10);
        }
      }
      goto LAB_005c3da0;
    }
  }
  else {
    iVar1 = cw_protocol_clone(param_3);
    *(int *)((int)__s + 0x10) = iVar1;
    if (iVar1 == 0) {
      if (capwap_err_switch == 0) {
        iVar1 = *(int *)((int)__s + 0x10);
        goto LAB_005c3e44;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        iVar1 = *(int *)((int)__s + 0x10);
        goto LAB_005c3e44;
      }
      uVar4 = 0x29e;
      goto LAB_005c3f34;
    }
    *(undefined2 *)((int)__s + 0xe) = 2;
  }
  iVar1 = *(int *)(param_1 + 0x10);
LAB_005c3da0:
  *(uint *)(param_1 + 0x10) = iVar1 + 4 + (uint)*(ushort *)((int)__s + 0xe);
  FUN_004086b0(param_1 + 0x14,__s);
  return 0;
}

