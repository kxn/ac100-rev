// func cloud_mngt_report_thread @ 0049b2a0 size=1396

void cloud_mngt_report_thread(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  FUN_0051ad88(&local_38);
  do {
    FUN_004082d0(cloud_mngt_msg_report_mutex,0xffffffff);
    while (iVar1 = FUN_004081b0(&g_cloud_mngt_msg_report_list), iVar1 == 0) {
      FUN_004086c0(cloud_mngt_msg_report_cond,cloud_mngt_msg_report_mutex,0xffffffff);
    }
    FUN_004082c0(&local_38,&g_cloud_mngt_msg_report_list);
    FUN_00407f30(cloud_mngt_msg_report_mutex);
    while (iVar1 = FUN_004081b0(&local_38), iVar1 != 0) {
      FUN_00408500(iVar1);
      iVar11 = *(int *)(iVar1 + 0xc);
      switch(iVar11) {
      case 3:
        uVar3 = 1;
        goto LAB_0049b74c;
      case 4:
        uVar3 = 0;
LAB_0049b74c:
        cloud_mngt_ap_add_report(uVar3);
        *(undefined4 *)(iVar1 + 0x10) = 0;
        break;
      case 5:
        cloud_mngt_client_first_report();
        *(undefined4 *)(iVar1 + 0x10) = 0;
        break;
      case 6:
        if (ap_report_switch == 0) {
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        else {
          FUN_0049743c();
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        break;
      case 7:
        if (ap_report_switch == 0) {
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        else {
          FUN_0049af28();
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        break;
      case 8:
        cloud_mngt_client_update_report();
        *(undefined4 *)(iVar1 + 0x10) = 0;
        break;
      case 9:
        if (ap_report_switch == 0) {
          *(undefined4 *)(iVar1 + 0x10) = 0;
          break;
        }
        iVar2 = json_object_new_object();
        uVar3 = json_object_new_array();
        uVar4 = json_object_new_object();
        uVar5 = json_object_new_object();
        FUN_0049164c(iVar2);
        cloud_mngt_AC_notice_param_add(iVar2);
        uVar6 = json_object_new_string("FITAP_RADIO_CONFIG_SYNC_NOTIFY");
        json_object_object_add(uVar4,"noticeType",uVar6);
        uVar6 = json_object_new_boolean(1);
        json_object_object_add(uVar5,"updateAll",uVar6);
        json_object_object_add(uVar4,"attachment",uVar5);
        json_object_array_add(uVar3,uVar4);
        json_object_object_add(iVar2,"notices",uVar3);
LAB_0049b604:
        if (ap_report_switch != 0) {
          cloud_mngt_obj_send_to_cloud(5,iVar2);
        }
        if (iVar2 != 0) goto LAB_0049b61c;
        goto LAB_0049b4e0;
      case 10:
      case 0xb:
        if (ap_report_switch != 0) {
          iVar2 = json_object_new_object();
          uVar3 = json_object_new_array();
          uVar4 = json_object_new_object();
          uVar5 = json_object_new_object();
          FUN_0049164c(iVar2);
          cloud_mngt_AC_notice_param_add(iVar2);
          uVar6 = json_object_new_string("FITAP_RRM_NOTIFY");
          json_object_object_add(uVar4,"noticeType",uVar6);
          if (iVar11 == 10) {
            pcVar10 = "start";
          }
          else {
            pcVar10 = "finish";
          }
          uVar6 = json_object_new_string(pcVar10);
          json_object_object_add(uVar5,"status",uVar6);
          json_object_object_add(uVar4,"attachment",uVar5);
          json_object_array_add(uVar3,uVar4);
          json_object_object_add(iVar2,"notices",uVar3);
          goto LAB_0049b604;
        }
        *(undefined4 *)(iVar1 + 0x10) = 0;
        break;
      case 0xc:
        uVar3 = 0;
        goto LAB_0049b4fc;
      case 0xd:
        uVar3 = 1;
        uVar4 = 0;
        goto LAB_0049b4d8;
      case 0xe:
        uVar3 = 2;
        uVar4 = 0;
        goto LAB_0049b4d8;
      case 0xf:
        uVar3 = 3;
        uVar4 = 0;
        goto LAB_0049b4d8;
      case 0x10:
        uVar3 = 1;
LAB_0049b4fc:
        nms_client_update_report(uVar3);
        *(undefined4 *)(iVar1 + 0x10) = 0;
        break;
      case 0x11:
        uVar3 = 1;
        goto LAB_0049b4d4;
      case 0x12:
        uVar3 = 2;
        goto LAB_0049b4d4;
      case 0x13:
        uVar3 = 3;
LAB_0049b4d4:
        uVar4 = 1;
LAB_0049b4d8:
        nms_report_ap_stats_update_report(uVar3,uVar4);
LAB_0049b4e0:
        *(undefined4 *)(iVar1 + 0x10) = 0;
        break;
      default:
        if (cloud_mngt_err_switch == '\0') break;
        printf("[CLOUD_MNGT_ERROR]%s()/%d Unknown msg op[%d]\n","cloud_mngt_msg_report_proc",0x1d9c,
               iVar11);
        iVar11 = *(int *)(iVar1 + 0x10);
        goto LAB_0049b378;
      case 0x15:
        if (ap_report_switch == 0) {
          cloud_mngt_sync_module_config_clear();
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
        else {
          iVar2 = json_object_new_object();
          uVar3 = json_object_new_array();
          uVar4 = json_object_new_object();
          uVar5 = json_object_new_array();
          FUN_0049164c(iVar2);
          cloud_mngt_AC_notice_param_add(iVar2);
          uVar6 = json_object_new_string("MODULE_CONFIG_SYNC_NOTIFY");
          json_object_object_add(uVar4,"noticeType",uVar6);
          FUN_004082d0(cloud_mngt_data_mutex,0xffffffff);
          for (iVar11 = FUN_004081b0(&g_cloud_mngt_sync_module_list); iVar11 != 0;
              iVar11 = FUN_00408680(iVar11)) {
            uVar6 = json_object_new_object();
            uVar7 = json_object_new_string(iVar11 + 0xc);
            json_object_object_add(uVar6,"moduleName",uVar7);
            uVar7 = json_object_new_array();
            for (iVar8 = FUN_004081b0(iVar11 + 0x40); iVar8 != 0; iVar8 = FUN_00408680(iVar8)) {
              uVar9 = json_object_new_string(iVar8 + 0xc);
              json_object_array_add(uVar7,uVar9);
            }
            json_object_object_add(uVar6,"subModuleNames",uVar7);
            json_object_array_add(uVar5,uVar6);
          }
          _cloud_mngt_sync_module_config_clear();
          FUN_00407f30(cloud_mngt_data_mutex);
          json_object_object_add(uVar4,"attachment",uVar5);
          json_object_array_add(uVar3,uVar4);
          json_object_object_add(iVar2,"notices",uVar3);
          if (ap_report_switch != 0) {
            cloud_mngt_obj_send_to_cloud(5,iVar2);
          }
          if (iVar2 == 0) goto LAB_0049b4e0;
LAB_0049b61c:
          json_object_put(iVar2);
          *(undefined4 *)(iVar1 + 0x10) = 0;
        }
      }
      iVar11 = *(int *)(iVar1 + 0x10);
LAB_0049b378:
      if (iVar11 != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      FUN_00407df0(iVar1);
    }
  } while( true );
}

