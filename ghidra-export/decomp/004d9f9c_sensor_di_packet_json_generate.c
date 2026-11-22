// func sensor_di_packet_json_generate @ 004d9f9c size=2024

char * sensor_di_packet_json_generate(uint param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *__format;
  int *piVar8;
  char *pcVar9;
  int in_stack_000000a8;
  int local_1c0 [13];
  int local_18c [12];
  int local_15c [13];
  int local_128 [64];
  
  uVar1 = (param_3 << 8) >> 0x18;
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : send_json_generate ENTER,chnl=%d\n",
           "sensor_di_packet_json_generate",0x79a,in_stack_000000a8);
  }
  if ((param_1 < 3) && (-1 < in_stack_000000a8)) {
    iVar3 = json_object_new_object();
    if (iVar3 == 0) {
      if (sensor_di_err_switch != 0) {
        pcVar9 = "[SENSOR_DI_ERROR]%s()/line %d : Malloc failed\n";
        uVar6 = 0x7aa;
        goto LAB_004da278;
      }
    }
    else {
      iVar4 = json_object_new_object();
      if (iVar4 == 0) {
        if (sensor_di_err_switch != 0) {
          uVar6 = 0x7b1;
LAB_004da2d0:
          printf("[SENSOR_DI_ERROR]%s()/line %d : Malloc failed\n","sensor_di_packet_json_generate",
                 uVar6);
        }
      }
      else {
        iVar5 = json_object_new_object();
        if (iVar5 == 0) {
          if (sensor_di_err_switch != 0) {
            printf("[SENSOR_DI_ERROR]%s()/line %d : Malloc failed\n",
                   "sensor_di_packet_json_generate",0x7b8);
          }
          if (iVar4 != 0) {
LAB_004da1b0:
            json_object_put(iVar4);
          }
        }
        else {
          memset(local_128,0,0x100);
          snprintf((char *)local_128,0x100,"%d",1);
          uVar6 = json_object_new_string(local_128);
          json_object_object_add(iVar5,"operation_id",uVar6);
          uVar6 = json_object_new_string("indepth_checkup");
          json_object_object_add(iVar5,"function",uVar6);
          memset(local_128,0,0x100);
          snprintf((char *)local_128,0x100,"%d",1);
          uVar6 = json_object_new_string(local_128);
          json_object_object_add(iVar5,"radio_id",uVar6);
          if (param_1 == 0) {
            memset(local_128,0,0x100);
            snprintf((char *)local_128,0x100,"%d",param_3 >> 0x18);
            uVar6 = json_object_new_string(local_128);
            json_object_object_add(iVar5,&DAT_006aa504,uVar6);
            memset(local_128,0,0x100);
            snprintf((char *)local_128,0x100,"%d",uVar1);
            uVar6 = json_object_new_string(local_128);
            json_object_object_add(iVar5,"band",uVar6);
            memset(local_128,0,0x100);
            snprintf((char *)local_128,0x100,"%d",0);
            uVar6 = json_object_new_string(local_128);
            json_object_object_add(iVar5,"channel",uVar6);
            uVar6 = json_object_new_string("on");
            json_object_object_add(iVar5,"enable",uVar6);
            memset(local_128,0,0x100);
            snprintf((char *)local_128,0x100,"%d",600);
            uVar6 = json_object_new_string(local_128);
            json_object_object_add(iVar5,"duration",uVar6);
            memset(local_128,0,0x100);
            snprintf((char *)local_128,0x100,"%d",5);
            uVar6 = json_object_new_string(local_128);
            json_object_object_add(iVar5,"sample_time",uVar6);
            iVar7 = json_object_new_object();
            if (iVar7 == 0) {
              if (sensor_di_err_switch != 0) {
                pcVar9 = "[SENSOR_DI_ERROR]%s()/line %d : Malloc failed\n";
                uVar6 = 0x7ca;
LAB_004da5f8:
                printf(pcVar9,"sensor_di_packet_json_generate",uVar6);
              }
LAB_004da1a8:
              json_object_put(iVar5);
              goto LAB_004da1b0;
            }
            memset(local_128,0,0x100);
            snprintf((char *)local_128,0x100,"%d",0);
            uVar6 = json_object_new_string(local_128);
            json_object_object_add(iVar7,"cache_flag",uVar6);
            pcVar9 = "cache_params";
          }
          else if (param_1 == 1) {
            iVar7 = json_object_new_string("off");
            pcVar9 = "enable";
          }
          else {
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_check_chnl_fit_setting ENTER, band=%d, chnl=%d\n"
                     ,"_sensor_di_check_chnl_fit_setting",0x1c5,uVar1,in_stack_000000a8);
            }
            memcpy(local_15c,&DAT_006ace00,0x34);
            memcpy(local_1c0 + 5,&DAT_006ace34,0x20);
            memcpy(local_18c,&DAT_006ace54,0x30);
            memcpy(local_1c0,&DAT_006ace84,0x14);
            memcpy(local_128,&DAT_006ace98,100);
            if (in_stack_000000a8 != 0) {
              switch(uVar1 - 1 & 0xff) {
              case 0:
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : match 2.4G band\n",
                         "_sensor_di_check_chnl_fit_setting",0x1d9);
                }
                iVar7 = 0;
                do {
                  piVar8 = (int *)((int)local_15c + iVar7);
                  iVar7 = iVar7 + 4;
                  if (in_stack_000000a8 == *piVar8) goto LAB_004da68c;
                } while (iVar7 != 0x34);
                break;
              case 1:
                iVar7 = 0;
                do {
                  iVar2 = iVar7 + 0x14;
                  iVar7 = iVar7 + 4;
                  if (in_stack_000000a8 == *(int *)((int)local_1c0 + iVar2)) goto LAB_004da68c;
                } while (iVar7 != 0x20);
                break;
              case 2:
                iVar7 = 0;
                do {
                  piVar8 = (int *)((int)local_18c + iVar7);
                  iVar7 = iVar7 + 4;
                  if (in_stack_000000a8 == *piVar8) goto LAB_004da68c;
                } while (iVar7 != 0x30);
                break;
              case 3:
                iVar7 = 0;
                piVar8 = local_1c0;
                do {
                  iVar7 = iVar7 + 4;
                  if (in_stack_000000a8 == *piVar8) goto LAB_004da68c;
                  piVar8 = (int *)((int)local_1c0 + iVar7);
                } while (iVar7 != 0x14);
                break;
              case 4:
                iVar7 = 0;
                do {
                  piVar8 = (int *)((int)local_128 + iVar7);
                  iVar7 = iVar7 + 4;
                  if (in_stack_000000a8 == *piVar8) goto LAB_004da68c;
                } while (iVar7 != 100);
                break;
              default:
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : no match band\n",
                         "_sensor_di_check_chnl_fit_setting",0x21b);
                }
              }
              if (sensor_di_err_switch != 0) {
                pcVar9 = "[SENSOR_DI_ERROR]%s()/line %d : chnl not fit.\n";
                uVar6 = 0x7dd;
                goto LAB_004da5f8;
              }
              goto LAB_004da1a8;
            }
LAB_004da68c:
            memset(local_128,0,0x100);
            snprintf((char *)local_128,0x100,"%d",in_stack_000000a8);
            iVar7 = json_object_new_string(local_128);
            pcVar9 = "channel";
          }
          json_object_object_add(iVar5,pcVar9,iVar7);
          json_object_object_add(iVar4,"set_indepth_checkup",iVar5);
          uVar6 = json_object_new_string(&DAT_00697f28);
          json_object_object_add(iVar3,"method",uVar6);
          json_object_object_add(iVar3,"indepth_checkup",iVar4);
          pcVar9 = (char *)json_object_to_json_string_ext(iVar3,0);
          pcVar9 = strdup(pcVar9);
          if (pcVar9 != (char *)0x0) {
            json_object_put(iVar3);
            if (sensor_di_debug_switch == 0) {
              return pcVar9;
            }
            __format = "[SENSOR_DI_DEBUG]%s()/line %d : generate json_string Success\n";
            uVar6 = 0x7f6;
            goto LAB_004da258;
          }
          if (sensor_di_err_switch != 0) {
            uVar6 = 0x7f1;
            goto LAB_004da2d0;
          }
        }
      }
      if (iVar3 != 0) {
        json_object_put(iVar3);
      }
    }
  }
  else if (sensor_di_err_switch != 0) {
    pcVar9 = "[SENSOR_DI_ERROR]%s()/line %d : invalid type or chnl input\n";
    uVar6 = 0x7a3;
LAB_004da278:
    printf(pcVar9,"sensor_di_packet_json_generate",uVar6);
  }
  pcVar9 = (char *)0x0;
  if (sensor_di_err_switch == 0) {
    return (char *)0x0;
  }
  __format = "[SENSOR_DI_ERROR]%s()/line %d : generate json_string Fail\n";
  uVar6 = 0x80e;
LAB_004da258:
  printf(__format,"sensor_di_packet_json_generate",uVar6);
  return pcVar9;
}

