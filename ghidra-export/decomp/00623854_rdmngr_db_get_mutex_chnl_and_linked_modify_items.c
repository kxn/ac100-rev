// func rdmngr_db_get_mutex_chnl_and_linked_modify_items @ 00623854 size=592

undefined4
rdmngr_db_get_mutex_chnl_and_linked_modify_items
          (undefined4 param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  int in_stack_00000054;
  int *in_stack_00000058;
  void *in_stack_0000005c;
  undefined4 in_stack_00000060;
  int local_a8 [16];
  int local_68 [16];
  
  param_3 = param_3 >> 0x18;
  memset(local_68,0,0x40);
  if (in_stack_00000054 == 0) {
    return 0xffffffff;
  }
  if (in_stack_00000058 == (int *)0x0) {
    return 0xffffffff;
  }
  if (in_stack_0000005c == (void *)0x0) {
    return 0xffffffff;
  }
  iVar6 = in_stack_00000054 + 0x218;
  uVar7 = *(undefined4 *)(in_stack_00000054 + 0x40);
  if (param_3 == 0) {
    iVar1 = apdb_24g_is_supported_by_id(uVar7,iVar6);
    if (iVar1 == 0) {
      uVar5 = *(undefined2 *)(in_stack_00000054 + 0x10);
    }
    else {
      iVar6 = apdb_get_24g_linked_modify_items(uVar7,iVar6,in_stack_00000060);
      if (iVar6 != 0) {
        return 0xffffffff;
      }
      uVar5 = *(undefined2 *)(in_stack_00000054 + 0x10);
    }
  }
  else if (param_3 == 1) {
    iVar1 = apdb_5g_is_supported_by_id(uVar7,iVar6);
    if (iVar1 == 0) {
      uVar5 = *(undefined2 *)(in_stack_00000054 + 0x10);
    }
    else {
      iVar6 = apdb_get_5g_linked_modify_items(uVar7,iVar6,in_stack_00000060);
      if (iVar6 != 0) {
        return 0xffffffff;
      }
      uVar5 = *(undefined2 *)(in_stack_00000054 + 0x10);
    }
  }
  else {
    uVar5 = *(undefined2 *)(in_stack_00000054 + 0x10);
  }
  iVar6 = rdmngr_db_get_mutex_chnl
                    (uVar7,in_stack_00000054 + 0x218,param_2 & 0xf,uVar5,param_4 >> 0x10,local_68,
                     param_3);
  if (iVar6 == 0) {
    memset(local_a8,0,0x40);
    piVar2 = local_a8;
    if (param_3 == 0) {
      iVar6 = 0;
      do {
        iVar6 = iVar6 + 1;
        *piVar2 = iVar6;
        piVar2 = piVar2 + 1;
      } while (iVar6 != 0xd);
      iVar6 = 0xc;
    }
    else {
      if (param_3 != 1) {
        iVar6 = -1;
        if ((rdmngr_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[RDMNGR_WARNING]%s()/%d invalid value freq_bind_type\n",
                 "rdmngr_db_get_default_mutex_chnl_exculde_selected_chnl",0x648);
        }
        goto LAB_00623918;
      }
      iVar6 = 7;
      memcpy(local_a8,&DAT_0070af58,0x20);
    }
    piVar2 = local_a8;
    iVar1 = 0;
    for (iVar4 = 0; iVar4 < iVar6 + 1; iVar4 = iVar4 + 1) {
      iVar3 = iVar1;
      if (param_4 >> 0x10 != *piVar2) {
        iVar3 = iVar1 + 1;
        local_68[iVar1] = *piVar2;
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar3;
    }
  }
LAB_00623918:
  *in_stack_00000058 = iVar6;
  memcpy(in_stack_0000005c,local_68,0x40);
  return 0;
}

