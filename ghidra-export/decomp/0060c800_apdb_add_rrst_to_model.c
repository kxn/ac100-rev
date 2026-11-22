// func apdb_add_rrst_to_model @ 0060c800 size=1

undefined4 apdb_add_rrst_to_model(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char acStack_110 [200];
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  int iStack_30;
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : apdb_add_rrst_to_model ENTER\n","apdb_add_rrst_to_model",
           0x2cf1);
  }
  uVar9 = 0xffffffff;
  memset(acStack_110,0,200);
  uVar8 = uVar9;
  if ((param_1 != 0) && (uVar8 = 0xffffffff, param_2 != 0)) {
    if (*(int *)(param_2 + 4) < 1) {
      uVar8 = uVar9;
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : ap_model->rrst_row_cnt=%d, invalid\n",
               "apdb_add_rrst_to_model",0x2d07);
      }
    }
    else {
      iStack_38 = json_object_new_array();
      iStack_40 = 0;
      if (iStack_38 == 0) {
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_radio_obj.\n";
        uVar8 = 0x2d0f;
      }
      else {
        for (; iStack_40 < *(int *)(param_2 + 4); iStack_40 = iStack_40 + 1) {
          iVar1 = json_object_new_object();
          if (iVar1 == 0) {
            if (apdb_err_switch != 0) {
              printf("[APDB_ERROR]%s()/line %d : Failed create json_feature_involved_obj.\n",
                     "apdb_add_rrst_to_model",0x2d18);
            }
            goto code_r0x0060ccf4;
          }
          memset(acStack_110,0,200);
          iVar11 = iStack_40 * 0x1fc;
          snprintf(acStack_110,200,"%d",*(undefined4 *)(*(int *)(param_2 + 0x34) + iVar11));
          iVar2 = json_object_new_string(acStack_110);
          if (iVar2 == 0) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of feature_involved.\n";
              uVar8 = 0x2d22;
code_r0x0060ccd8:
              printf(pcVar7,"apdb_add_rrst_to_model",uVar8);
            }
code_r0x0060cce0:
            if (iVar1 != 0) {
              json_object_put(iVar1);
            }
code_r0x0060ccf4:
            json_object_put(iStack_38);
            return 0xffffffff;
          }
          json_object_object_add(iVar1,"feature_involved",iVar2);
          memset(acStack_110,0,200);
          iVar2 = _apdb_parse_rrst_region_code_list_from_apdb
                            (acStack_110,*(int *)(param_2 + 0x34) + iVar11 + 9);
          if (iVar2 != 0) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed parse region_list from apdb.\n";
              uVar8 = 0x2d2c;
              goto code_r0x0060ccd8;
            }
            goto code_r0x0060cce0;
          }
          iVar2 = json_object_new_string(acStack_110);
          if (iVar2 == 0) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of region_list2.\n";
              uVar8 = 0x2d33;
              goto code_r0x0060ccd8;
            }
            goto code_r0x0060cce0;
          }
          json_object_object_add(iVar1,"region_list",iVar2);
          memset(acStack_110,0,200);
          snprintf(acStack_110,200,"%d",*(undefined4 *)(*(int *)(param_2 + 0x34) + iVar11 + 4));
          iVar2 = json_object_new_string(acStack_110);
          if (iVar2 == 0) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of table_index.\n";
              uVar8 = 0x2d3f;
              goto code_r0x0060ccd8;
            }
            goto code_r0x0060cce0;
          }
          json_object_object_add(iVar1,"table_index",iVar2);
          memset(acStack_110,0,200);
          snprintf(acStack_110,200,"%d",(uint)*(byte *)(*(int *)(param_2 + 0x34) + iVar11 + 8));
          iVar2 = json_object_new_string(acStack_110);
          if (iVar2 == 0) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of radio_num.\n";
              uVar8 = 0x2d4b;
              goto code_r0x0060ccd8;
            }
            goto code_r0x0060cce0;
          }
          json_object_object_add(iVar1,"radio_num",iVar2);
          iStack_44 = json_object_new_array();
          if (iStack_44 == 0) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_radio_id_array_obj.\n";
              uVar8 = 0x2d55;
              goto code_r0x0060ccd8;
            }
            goto code_r0x0060cce0;
          }
          iVar2 = json_object_new_array();
          if (iVar2 == 0) {
            if (apdb_err_switch != 0) {
              printf("[APDB_ERROR]%s()/line %d : Failed create json_radio_abs_status_array_obj.\n",
                     "apdb_add_rrst_to_model",0x2d5c);
            }
            iVar5 = 0;
            iVar4 = 0;
            iVar3 = 0;
code_r0x0060cdc0:
            json_object_put(iStack_44);
            if (iVar2 != 0) {
              json_object_put(iVar2);
            }
            if (iVar3 != 0) {
              json_object_put(iVar3);
            }
            if (iVar4 != 0) {
              json_object_put(iVar4);
            }
            if (iVar5 != 0) {
              json_object_put(iVar5);
            }
            goto code_r0x0060cce0;
          }
          iVar3 = json_object_new_array();
          if (iVar3 == 0) {
            if (apdb_err_switch == 0) {
              iVar5 = 0;
              iVar4 = 0;
            }
            else {
              iVar5 = 0;
              printf("[APDB_ERROR]%s()/line %d : Failed create json_radio_bind_id.\n",
                     "apdb_add_rrst_to_model",0x2d63);
              iVar4 = 0;
            }
            goto code_r0x0060cdc0;
          }
          iVar4 = json_object_new_array();
          if (iVar4 == 0) {
            iVar5 = 0;
            if (apdb_err_switch != 0) {
              printf("[APDB_ERROR]%s()/line %d : Failed create json_bandwidth_array_obj.\n",
                     "apdb_add_rrst_to_model",0x2d6a);
              iVar5 = 0;
            }
            goto code_r0x0060cdc0;
          }
          iVar5 = json_object_new_array();
          if (iVar5 == 0) {
            if (apdb_err_switch != 0) {
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json_channel_array_obj.\n";
              uVar8 = 0x2d71;
code_r0x0060ce24:
              printf(pcVar7,"apdb_add_rrst_to_model",uVar8);
            }
            goto code_r0x0060cdc0;
          }
          for (iStack_3c = 0; iStack_48 = *(int *)(param_2 + 0x34) + iVar11,
              iStack_3c < (int)(uint)*(byte *)(iStack_48 + 8); iStack_3c = iStack_3c + 1) {
            memset(acStack_110,0,200);
            iVar10 = iStack_3c * 0x74;
            snprintf(acStack_110,200,"%d",(uint)*(byte *)(iStack_48 + iVar10 + 0x98));
            iVar6 = json_object_new_string(acStack_110);
            if (iVar6 == 0) {
              if (apdb_err_switch == 0) goto code_r0x0060cdc0;
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of radio_id.\n";
              uVar8 = 0x2d7e;
              goto code_r0x0060ce24;
            }
            json_object_array_add(iStack_44,iVar6);
            memset(acStack_110,0,200);
            snprintf(acStack_110,200,"%d",
                     *(undefined4 *)(*(int *)(param_2 + 0x34) + iVar11 + iVar10 + 0x2c));
            iVar6 = json_object_new_string(acStack_110);
            if (iVar6 == 0) {
              if (apdb_err_switch == 0) goto code_r0x0060cdc0;
              pcVar7 = 
              "[APDB_ERROR]%s()/line %d : Failed create json obj of radio_abstract_status.\n";
              uVar8 = 0x2d8b;
              goto code_r0x0060ce24;
            }
            json_object_array_add(iVar2,iVar6);
            memset(acStack_110,0,200);
            snprintf(acStack_110,200,"%d",
                     (uint)*(byte *)(*(int *)(param_2 + 0x34) + iVar11 + iVar10 + 0x9a));
            iVar6 = json_object_new_string(acStack_110);
            if (iVar6 == 0) {
              if (apdb_err_switch == 0) goto code_r0x0060cdc0;
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of bind_id.\n";
              uVar8 = 0x2d97;
              goto code_r0x0060ce24;
            }
            json_object_array_add(iVar3,iVar6);
            memset(acStack_110,0,200);
            iVar6 = _apdb_parse_rrst_bandwidth_from_apdb
                              (acStack_110,
                               *(undefined1 *)(*(int *)(param_2 + 0x34) + iVar11 + iVar10 + 0x99));
            if (iVar6 == -1) {
              if (apdb_err_switch == 0) goto code_r0x0060cdc0;
              pcVar7 = "[APDB_ERROR]%s()/line %d : parse_rrst_bandwidth_from_apdb fail\n";
              uVar8 = 0x2da1;
              goto code_r0x0060ce24;
            }
            iVar6 = json_object_new_string(acStack_110);
            if (iVar6 == 0) {
              if (apdb_err_switch == 0) goto code_r0x0060cdc0;
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of bandwidth.\n";
              uVar8 = 0x2da7;
              goto code_r0x0060ce24;
            }
            json_object_array_add(iVar4,iVar6);
            iStack_48 = *(int *)(param_2 + 0x34) + iVar11;
            uStack_34 = *(undefined4 *)(iStack_48 + iVar10 + 0x9c);
            iStack_30 = (int)*(short *)(iStack_48 + iVar10 + 0x30);
            memset(acStack_110,0,200);
            iVar6 = _apdb_parse_rrst_channel_from_apdb
                              (acStack_110,iStack_48 + iVar10 + 0x32,iStack_30,uStack_34);
            if (iVar6 == -1) {
              if (apdb_err_switch == 0) goto code_r0x0060cdc0;
              pcVar7 = "[APDB_ERROR]%s()/line %d : parse_rrst_channel_from_apdb fail\n";
              uVar8 = 0x2db4;
              goto code_r0x0060ce24;
            }
            iVar6 = json_object_new_string(acStack_110);
            if (iVar6 == 0) {
              if (apdb_err_switch == 0) goto code_r0x0060cdc0;
              pcVar7 = "[APDB_ERROR]%s()/line %d : Failed create json obj of channel.\n";
              uVar8 = 0x2dba;
              goto code_r0x0060ce24;
            }
            json_object_array_add(iVar5,iVar6);
          }
          json_object_object_add(iVar1,"radio_id",iStack_44);
          json_object_object_add(iVar1,"radio_abstract_status",iVar2);
          json_object_object_add(iVar1,"bind_id",iVar3);
          json_object_object_add(iVar1,"bandwidth",iVar4);
          json_object_object_add(iVar1,"channel",iVar5);
          json_object_array_add(iStack_38,iVar1);
        }
        uVar9 = 0;
        json_object_object_add(param_1,"radioLinkageTable",iStack_38);
        if (apdb_debug_switch == 0) {
          return 0;
        }
        pcVar7 = "[APDB_DEBUG]%s()/line %d : apdb_add_rrst_to_model success EXIT\n";
        uVar8 = 0x2dd8;
      }
      printf(pcVar7,"apdb_add_rrst_to_model",uVar8);
      uVar8 = uVar9;
    }
  }
  return uVar8;
}

