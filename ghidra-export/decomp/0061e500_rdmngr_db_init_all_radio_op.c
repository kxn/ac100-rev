// func rdmngr_db_init_all_radio_op @ 0061e500 size=852

undefined4 rdmngr_db_init_all_radio_op(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  char *__format;
  undefined4 uVar7;
  
  if (param_1 == (uint *)0x0) {
    if (rdmngr_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[RDMNGR_ERROR]%s()/%d Invalid rd entry.\n";
      uVar7 = 0xf72;
      goto LAB_0061e608;
    }
  }
  else {
    if ((*param_1 & 0xf) == 0) {
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[RDMNGR_ERROR]%s()/%d Invalid rd_id.\n";
      uVar7 = 0xf79;
LAB_0061e608:
      printf(__format,"rdmngr_db_init_all_radio_op",uVar7);
      return 0xffffffff;
    }
    uVar2 = rdmngr_db_generate_rd_idx_by_rd_id();
    iVar1 = DAT_007cc65c;
    if (-1 < (int)uVar2) {
      iVar3 = apmngr_db_get_ap_max();
      iVar4 = apmngr_db_get_template_max();
      iVar5 = apmngr_db_get_sensor_max();
      if (uVar2 < (uint)((iVar3 + iVar4 + iVar5) * iVar1)) {
        FUN_004082d0(DAT_007cc64c,0xffffffff);
        iVar1 = *(int *)(DAT_007cc650 + uVar2 * 8 + 4);
        if (iVar1 == 0) {
          if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[RDMNGR_ERROR]%s()/%d idx[%d] is invalid!\n","rdmngr_db_init_all_radio_op",0xf87
                   ,uVar2);
          }
          FUN_00407f30(DAT_007cc64c);
          return 0xffffffff;
        }
        if (rdmngr_debug_switch == 0) {
          iVar3 = (int)*(char *)(iVar1 + 0x48);
        }
        else {
          iVar4 = is_target_debug_ap();
          iVar3 = (int)*(char *)(iVar1 + 0x48);
          if (iVar4 != 0) {
            printf("[RDMNGR_DEBUG]%s()/%d rd_id:%d, cfg:%d, info:%d\n","rdmngr_db_init_all_radio_op"
                   ,0xf8e,*param_1,iVar3,(uint)*(byte *)(iVar1 + 0x4e));
            iVar3 = (int)*(char *)(iVar1 + 0x48);
          }
        }
        if (iVar3 == 1) {
          if (*(char *)(iVar1 + 0x4e) == '\x03') {
            *(undefined1 *)(iVar1 + 0x4e) = 1;
            if (rdmngr_debug_switch == 0) {
              cVar6 = *(char *)(iVar1 + 0x48);
            }
            else {
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                cVar6 = *(char *)(iVar1 + 0x48);
              }
              else {
                printf("[RDMNGR_DEBUG]%s()/%d cfg:%d, info:%d\n","rdmngr_db_init_all_radio_op",0xf94
                       ,(int)*(char *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x4e));
                cVar6 = *(char *)(iVar1 + 0x48);
              }
            }
          }
          else {
            cVar6 = *(char *)(iVar1 + 0x48);
          }
        }
        else {
          cVar6 = *(char *)(iVar1 + 0x48);
        }
        if (cVar6 == '\0') {
          if (*(char *)(iVar1 + 0x4e) == '\x04') {
            *(undefined1 *)(iVar1 + 0x4e) = 2;
          }
          cVar6 = *(char *)(iVar1 + 0x41);
        }
        else {
          cVar6 = *(char *)(iVar1 + 0x41);
        }
        if (cVar6 == '\x01') {
          if (*(char *)(iVar1 + 0x4f) != '\x04') {
            cVar6 = *(char *)(iVar1 + 0x42);
            goto LAB_0061e6dc;
          }
          *(undefined1 *)(iVar1 + 0x4f) = 1;
        }
        else if ((cVar6 == '\0') && (*(char *)(iVar1 + 0x4f) == '\x03')) {
          *(undefined1 *)(iVar1 + 0x4f) = 2;
        }
        cVar6 = *(char *)(iVar1 + 0x42);
LAB_0061e6dc:
        if (cVar6 == '\x01') {
          if (*(char *)(iVar1 + 0x50) == '\x04') {
            *(undefined1 *)(iVar1 + 0x50) = 1;
          }
        }
        else if ((cVar6 == '\0') && (*(char *)(iVar1 + 0x50) == '\x03')) {
          *(undefined1 *)(iVar1 + 0x50) = 2;
        }
        memcpy(param_1 + 0x13,(void *)(iVar1 + 0x4c),5);
        FUN_00407f30(DAT_007cc64c);
        return 0;
      }
    }
    if (rdmngr_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        printf("[RDMNGR_ERROR]%s()/%d Invalid rd_idx:%d\n","rdmngr_db_init_all_radio_op",0xf80,uVar2
              );
        return 0xffffffff;
      }
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

