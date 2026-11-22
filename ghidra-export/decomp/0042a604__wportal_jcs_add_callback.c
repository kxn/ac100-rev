// func _wportal_jcs_add_callback @ 0042a604 size=2000

void _wportal_jcs_add_callback(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  iVar1 = json_object_object_get(param_1,"type");
  if (iVar1 == 0) {
LAB_0042a668:
    if (jcs_err_switch == 0) {
      uVar5 = 0;
      goto LAB_0042a67c;
    }
    pcVar3 = "_wportal_jcs_add_callback";
    uVar4 = 0x2422;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0042a668;
      uVar6 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
    if (iVar1 == 4) {
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Add nsa\n","_wportal_jcs_add_callback",0x2437);
      }
      _wportal_nsa_add(param_1,1);
      uVar5 = 0;
      goto LAB_0042a67c;
    }
    if (iVar1 < 5) {
      if (iVar1 == 2) {
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Add free strategy\n","_wportal_jcs_add_callback",0x242c);
        }
        _wportal_free_strategy_add(param_1);
        uVar5 = 0;
      }
      else if (iVar1 < 3) {
        uVar5 = 0;
        if (iVar1 == 1) {
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Add page\n","_wportal_jcs_add_callback",0x2427);
          }
          _wportal_page_add(param_1);
          uVar5 = 0;
        }
      }
      else {
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Add authed user\n","_wportal_jcs_add_callback",0x2431);
        }
        uVar5 = _wportal_authed_user_add(param_1,1);
      }
      goto LAB_0042a67c;
    }
    if (iVar1 == 700) {
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Add failed auth result.\n","_wportal_jcs_add_callback",0x2441)
        ;
      }
      _wportal_add_failed_auth_result(param_1,1);
      uVar5 = 0;
      goto LAB_0042a67c;
    }
    if (iVar1 != 0xffff) {
      uVar5 = 0;
      if (iVar1 == 200) {
        if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Add radius entry\n","_wportal_jcs_add_callback",0x243c);
        }
        _wportal_radius_add(param_1);
        uVar5 = 0;
      }
      goto LAB_0042a67c;
    }
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Add auth from datasync.\n","_wportal_jcs_add_callback",0x2446);
    }
    iVar1 = json_object_object_get(param_1,"datasync_op_type");
    if (iVar1 == 0) {
LAB_0042a834:
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_datasync_request_dispatch",0x38d6);
      }
      iVar2 = -1;
      if (iVar1 != 0) goto LAB_0042a84c;
LAB_0042ab04:
      uVar5 = 0;
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Unkown type from datasync!\n",
               "_wportal_datasync_request_dispatch",0x38eb);
      }
      goto LAB_0042a67c;
    }
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar2 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0042a834;
      uVar6 = json_object_get_double(iVar1);
      iVar2 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
LAB_0042a84c:
    json_object_object_del(param_1,"datasync_op_type");
    if (iVar2 != 1) {
      uVar5 = 0;
      if (iVar2 == 2) goto LAB_0042a67c;
      if (iVar2 != 0) goto LAB_0042ab04;
      iVar1 = json_object_object_get(param_1,"datasync_data_type");
      if (iVar1 == 0) {
LAB_0042a8b0:
        if (jcs_err_switch == 0) {
          uVar4 = 0xffffffff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_datasync_add_handler",0x38f6);
          uVar4 = 0xffffffff;
        }
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 3) {
          iVar1 = json_object_get_int(iVar1);
        }
        else {
          iVar2 = json_object_get_type();
          if (iVar2 != 2) goto LAB_0042a8b0;
          uVar6 = json_object_get_double(iVar1);
          iVar1 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        }
        if (iVar1 == 4) {
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Add nsa from datasync\n","_wportal_datasync_add_handler",
                   0x3904);
          }
          _wportal_nsa_add(param_1,0);
          uVar4 = 0xffffffff;
        }
        else if (iVar1 < 5) {
          if (iVar1 == 3) {
            if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[WPORTAL_INFO]%s()/%d Add authed user from datasync\n",
                     "_wportal_datasync_add_handler",0x38ff);
            }
            uVar4 = _wportal_authed_user_add(param_1,0);
          }
          else {
            uVar4 = 0xffffffff;
          }
        }
        else if (iVar1 == 5) {
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Sync all nsa from datasync\n",
                   "_wportal_datasync_add_handler",0x3909);
          }
          wportal_db_nsa_rbtree_load(param_1,0);
          uVar4 = 0xffffffff;
        }
        else if (iVar1 == 700) {
          if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d Add failed auth result.\n","_wportal_datasync_add_handler"
                   ,0x3911);
          }
          _wportal_add_failed_auth_result(param_1,0);
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = 0xffffffff;
        }
      }
      uVar5 = 0;
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d _wportal_datasync_add_handler ret %d\n",
               "_wportal_datasync_add_handler",0x3919,uVar4);
      }
      goto LAB_0042a67c;
    }
    iVar1 = json_object_object_get(param_1,"datasync_data_type");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0042aad8;
        uVar6 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
      if (iVar1 != 4) {
        if (iVar1 < 5) {
          uVar5 = 0;
          if (iVar1 == 3) {
            if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[WPORTAL_INFO]%s()/%d Del authed user from datasync\n",
                     "_wportal_datasync_del_handler",0x3931);
            }
            _wportal_authed_user_del(param_1,0);
            uVar5 = 0;
          }
          goto LAB_0042a67c;
        }
        if ((iVar1 != 7) && (uVar5 = 0, iVar1 != 9)) goto LAB_0042a67c;
      }
      if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_INFO]%s()/%d Del nsa from datasync\n","_wportal_datasync_del_handler",
               0x3938);
      }
      _wportal_nsa_del(param_1,0);
      uVar5 = 0;
      goto LAB_0042a67c;
    }
LAB_0042aad8:
    uVar5 = 0;
    if (jcs_err_switch == 0) goto LAB_0042a67c;
    pcVar3 = "_wportal_datasync_del_handler";
    uVar4 = 0x3928;
  }
  uVar5 = 0;
  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",pcVar3,uVar4
        );
LAB_0042a67c:
  uVar5 = json_object_new_int(uVar5);
  json_object_object_add(param_2,&DAT_00676a24,uVar5);
  return;
}

