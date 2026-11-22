// func apmngr_db_group_delete @ 00538e48 size=488

void apmngr_db_group_delete(ushort *param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  void *__s;
  int iVar3;
  
  if ((param_1 == (ushort *)0x0) || (param_2 < 1)) {
    return;
  }
  iVar3 = 0;
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  do {
    if ((int)(uint)*param_1 < apmngr_group_num_max) {
      __s = (void *)(g_apmngr_group_array + (uint)*param_1 * 0x84);
      if (*(int *)((int)__s + 0x10) == 0) {
        if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          uVar2 = 0x604;
          __format = "[APMNGR_ERROR]%s()/%d Group id[%d] not in use.\n";
          goto LAB_00538f90;
        }
      }
      else {
        iVar1 = FUN_00407fe0((int)__s + 0x78);
        if (iVar1 == 0) {
          FUN_00408500(__s);
          memset(__s,0,0x84);
          FUN_0051ad88((int)__s + 0x78);
        }
        else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          uVar2 = 0x60a;
          __format = "[APMNGR_ERROR]%s()/%d Group id[%d] is not empty.\n";
          goto LAB_00538f90;
        }
      }
    }
    else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = 0x5fd;
      __format = "[APMNGR_ERROR]%s()/%d Invalid group id[%d].\n";
LAB_00538f90:
      printf(__format,"apmngr_db_group_delete",uVar2,(uint)*param_1);
    }
    iVar3 = iVar3 + 1;
    param_1 = param_1 + 1;
    if (iVar3 == param_2) {
      FUN_00407f30(apmngr_db_mutex);
      return;
    }
  } while( true );
}

