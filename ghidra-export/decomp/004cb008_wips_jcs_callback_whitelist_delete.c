// func wips_jcs_callback_whitelist_delete @ 004cb008 size=992

void wips_jcs_callback_whitelist_delete(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  char acStack_128 [256];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (sensor_err_switch == '\0') goto LAB_004cb188;
    __format = "[SENSOR_ERROR]%s()/%d inputs error.\n";
    uVar7 = 0x7f7;
  }
  else {
    piVar1 = (int *)FUN_00408450((uint)g_whitelist_max_size << 2,0x7fb);
    if (piVar1 != (int *)0x0) {
      iVar2 = json_object_object_get(param_1,"whitelist_ids");
      if (iVar2 != 0) {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 5) {
          piVar6 = piVar1;
          for (iVar3 = 0;
              (iVar4 = json_object_array_length(iVar2), iVar3 < iVar4 &&
              (iVar3 < (int)(uint)g_whitelist_max_size)); iVar3 = iVar3 + 1) {
            iVar4 = json_object_array_get_idx(iVar2,iVar3);
            if (iVar4 == 0) {
LAB_004cb320:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"wips_jcs_callback_whitelist_delete",0x809);
              }
              *piVar6 = -1;
            }
            else {
              iVar5 = json_object_get_type(iVar4);
              if (iVar5 == 3) {
                iVar4 = json_object_get_int(iVar4);
                *piVar6 = iVar4;
              }
              else {
                iVar5 = json_object_get_type();
                if (iVar5 != 2) goto LAB_004cb320;
                uVar8 = json_object_get_double(iVar4);
                iVar4 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
                *piVar6 = iVar4;
              }
            }
            piVar6 = piVar6 + 1;
          }
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 4) {
            iVar2 = json_object_object_length(iVar2);
            iVar3 = 0;
            if (iVar2 == 0) goto LAB_004cb0b4;
          }
          iVar3 = 0;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                   ,"wips_jcs_callback_whitelist_delete",0x809);
          }
        }
LAB_004cb0b4:
        uVar7 = 0;
        iVar2 = 0;
        FUN_004082d0(wips_global_mutex,0xffffffff);
        piVar6 = piVar1;
        do {
          while( true ) {
            if (iVar3 <= iVar2) {
              FUN_00407f30(wips_global_mutex);
              memset(acStack_128,0,0x100);
              snprintf(acStack_128,0x100,"%d",uVar7);
              uVar7 = json_object_new_string(acStack_128);
              json_object_object_add(param_2,&DAT_00676a24,uVar7);
              FUN_00407df0(piVar1);
              return;
            }
            iVar5 = *piVar6;
            iVar4 = FUN_004086a0(g_whitelist_id_allocator,iVar5);
            if (iVar4 != 0) break;
            uVar7 = 0xffffffff;
            if (sensor_err_switch == '\0') goto LAB_004cb100;
            printf("[SENSOR_ERROR]%s()/%d whitelist[id=%d] not found\n",
                   "wips_jcs_callback_whitelist_delete",0x811,iVar5);
            iVar2 = iVar2 + 1;
            piVar6 = piVar6 + 1;
          }
          for (iVar4 = FUN_004081b0(&g_white_list); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
            if (*(int *)(iVar4 + 0xc) == iVar5) {
              whitelist_entry_delete(iVar4);
            }
          }
LAB_004cb100:
          iVar2 = iVar2 + 1;
          piVar6 = piVar6 + 1;
        } while( true );
      }
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d get key[whitelist_ids] error\n",
               "wips_jcs_callback_whitelist_delete",0x806);
      }
      FUN_00407df0(piVar1);
      goto LAB_004cb188;
    }
    if (sensor_err_switch == '\0') goto LAB_004cb188;
    __format = "[SENSOR_ERROR]%s()/%d out of memory.\n";
    uVar7 = 0x7fe;
  }
  printf(__format,"wips_jcs_callback_whitelist_delete",uVar7);
LAB_004cb188:
  memset(acStack_128,0,0x100);
  snprintf(acStack_128,0x100,"%d",0xffffffff);
  uVar7 = json_object_new_string(acStack_128);
  json_object_object_add(param_2,&DAT_00676a24,uVar7);
  return;
}

