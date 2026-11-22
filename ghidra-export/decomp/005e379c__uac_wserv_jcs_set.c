// func _uac_wserv_jcs_set @ 005e379c size=1496

void _uac_wserv_jcs_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  iVar1 = json_object_object_get(param_1,"operation");
  if (iVar1 == 0) {
    if (g_wserv_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    __format = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
    uVar3 = 0xe44;
    pcVar6 = "operation";
LAB_005e3aec:
    printf(__format,"_uac_wserv_jcs_set",uVar3,pcVar6);
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    pcVar6 = (char *)json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar7 = json_object_get_double(iVar1);
      pcVar6 = (char *)__fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
    else {
      pcVar6 = (char *)0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_set",0xe45);
      }
    }
  }
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_set op=%d.\r\n","_uac_wserv_jcs_set",0xe46,
           pcVar6);
  }
  switch(pcVar6) {
  case (char *)0x0:
    _uac_wserv_jcs_modify(param_1,param_2);
    return;
  case (char *)0x1:
    uVar3 = 1;
    break;
  case (char *)0x2:
    uVar3 = 0;
    break;
  case (char *)0x3:
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(param_1), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_set op=%d.\r\n","_uac_wserv_jcs_set",0xe53,3
            );
    }
    uVar3 = 1;
    goto LAB_005e38f4;
  case (char *)0x4:
    uVar3 = 0;
LAB_005e38f4:
    _uac_wserv_jcs_wserv_op(param_1,param_2,uVar3);
    return;
  case (char *)0x5:
  case (char *)0x6:
  case (char *)0x7:
    iVar1 = json_object_object_get(param_1,"radio_id");
    if (iVar1 == 0) {
      if (g_wserv_error == 0) {
        return;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return;
      }
      __format = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
      uVar3 = 0xe5e;
      pcVar6 = "radio_id";
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar3 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar7 = json_object_get_double(iVar1);
          uVar3 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
        }
        else {
          uVar3 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_wserv_jcs_set",0xe5f);
          }
        }
      }
      iVar1 = json_object_object_get(param_1,"rd_num_binded");
      if (iVar1 == 0) {
        if (g_wserv_error == 0) {
          return;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return;
        }
        __format = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
        uVar3 = 0xe62;
        pcVar6 = "rd_num_binded";
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          uVar5 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 == 2) {
            uVar7 = json_object_get_double(iVar1);
            uVar5 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
          }
          else {
            uVar5 = 0xffffffff;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_uac_wserv_jcs_set",0xe63);
            }
          }
        }
        if (pcVar6 == (char *)0x5) {
          iVar1 = wserv_db_ap_firm(uVar3,uVar5);
          if (iVar1 == 0) {
            if (g_wserv_debug == 0) {
              return;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return;
            }
            pcVar6 = "<wserv>[debug]%s(): %d  -> firm ap[%d], rd_cnt[%d].\r\n";
            uVar4 = 0xe69;
            goto LAB_005e3a90;
          }
        }
        else if (pcVar6 == (char *)0x6) {
          iVar1 = wserv_db_ap_del(uVar3,uVar5);
          if (iVar1 == 0) {
            if (g_wserv_debug == 0) {
              return;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return;
            }
            pcVar6 = "<wserv>[debug]%s(): %d  -> del ap[%d], rd_cnt[%d].\r\n";
            uVar4 = 0xe71;
            goto LAB_005e3a90;
          }
        }
        else {
          iVar1 = uac_wservice_ap_enter_run(uVar3,uVar5,1);
          if (iVar1 == 0) {
            if (g_wserv_debug == 0) {
              return;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return;
            }
            pcVar6 = "<wserv>[debug]%s(): %d  -> ap[%d], rd_cnt[%d] enter run.\r\n";
            uVar4 = 0xe79;
LAB_005e3a90:
            printf(pcVar6,"_uac_wserv_jcs_set",uVar4,uVar3,uVar5);
            return;
          }
        }
        if (g_wserv_error == 0) {
          return;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return;
        }
        __format = "<wserv>[error]%s(): %d  -> op[%d] fail\r\n";
        uVar3 = 0xe7e;
      }
    }
    goto LAB_005e3aec;
  default:
    wserv_db_print_all();
    wserv_rd_print_all();
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[error]%s(): %d  -> invalid op[%d]\r\n","_uac_wserv_jcs_set",0xe87,pcVar6);
    }
    uVar3 = json_object_new_int(0xffffffff);
    json_object_object_add(param_2,"serv_id",uVar3);
    return;
  }
  _uac_wserv_jcs_rd_op(param_1,param_2,uVar3);
  return;
}

