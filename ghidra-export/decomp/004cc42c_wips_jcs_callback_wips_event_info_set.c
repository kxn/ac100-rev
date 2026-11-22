// func wips_jcs_callback_wips_event_info_set @ 004cc42c size=1328

void wips_jcs_callback_wips_event_info_set(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  void *__src;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  undefined8 uVar13;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    if (sensor_err_switch == '\0') goto LAB_004cc638;
    pcVar6 = "[SENSOR_ERROR]%s()/%d inputs error.\n";
    uVar11 = 0x6b9;
  }
  else {
    piVar1 = (int *)FUN_00408450((uint)g_wips_info_max_size << 2,0x6bd);
    if (piVar1 != (int *)0x0) {
      iVar2 = json_object_object_get(param_1,"wips_info_ids");
      if (iVar2 == 0) {
        if (sensor_err_switch != '\0') {
          pcVar6 = "[SENSOR_ERROR]%s()/%d get key[wips_info_ids] error\n";
          uVar11 = 0x6c8;
LAB_004cc8b4:
          printf(pcVar6,"wips_jcs_callback_wips_event_info_set",uVar11);
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 5) {
          piVar10 = piVar1;
          for (iVar3 = 0;
              (iVar4 = json_object_array_length(iVar2), iVar3 < iVar4 &&
              (iVar3 < (int)(uint)g_wips_info_max_size)); iVar3 = iVar3 + 1) {
            iVar4 = json_object_array_get_idx(iVar2,iVar3);
            if (iVar4 == 0) {
LAB_004cc73c:
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"wips_jcs_callback_wips_event_info_set",0x6cb);
              }
              *piVar10 = -1;
            }
            else {
              iVar9 = json_object_get_type(iVar4);
              if (iVar9 == 3) {
                iVar4 = json_object_get_int(iVar4);
                *piVar10 = iVar4;
              }
              else {
                iVar9 = json_object_get_type();
                if (iVar9 != 2) goto LAB_004cc73c;
                uVar13 = json_object_get_double(iVar4);
                iVar4 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                *piVar10 = iVar4;
              }
            }
            piVar10 = piVar10 + 1;
          }
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 4) {
            iVar2 = json_object_object_length(iVar2);
            iVar3 = 0;
            if (iVar2 == 0) goto LAB_004cc4dc;
          }
          iVar3 = 0;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                   ,"wips_jcs_callback_wips_event_info_set",0x6cb);
          }
        }
LAB_004cc4dc:
        iVar2 = json_object_object_get(param_1,"operation");
        if (iVar2 == 0) {
LAB_004cc518:
          iVar2 = -1;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "wips_jcs_callback_wips_event_info_set",0x6ce);
          }
        }
        else {
          iVar4 = json_object_get_type(iVar2);
          if (iVar4 == 3) {
            iVar2 = json_object_get_int(iVar2);
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_004cc518;
            uVar13 = json_object_get_double(iVar2);
            iVar2 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          }
        }
        iVar4 = FUN_00408450(iVar3 * 0xb0,0x6d0);
        if (iVar4 != 0) {
          iVar9 = 0;
          iVar12 = 0;
          FUN_004082d0(wips_global_mutex,0xffffffff);
          piVar10 = piVar1;
          while (iVar12 < iVar3) {
            iVar8 = *piVar10;
            iVar5 = FUN_004086a0(g_wips_id_allocator,iVar8);
            if (iVar5 == 0) {
              uVar11 = 0;
              if (sensor_err_switch != '\0') {
                printf("[SENSOR_ERROR]%s()/%d wips event[id=%d] not found\n",
                       "wips_jcs_callback_wips_event_info_set",0x6dd,iVar8);
              }
              goto LAB_004cc778;
            }
            __src = *(void **)(g_wips_id2entry + iVar8 * 4);
            if (iVar2 - 1U < 2) {
              iVar5 = iVar9 * 0xb0;
              iVar9 = iVar9 + 1;
              iVar12 = iVar12 + 1;
              memcpy((void *)(iVar4 + iVar5),__src,0xb0);
              piVar10 = piVar10 + 1;
            }
            else {
              if (((iVar2 == 3) && (*(int *)((int)__src + 0x98) - 5U < 2)) &&
                 (iVar5 = whitelist_entry_add((int)__src + 0x48,&DAT_00688af8,0), iVar5 == -5)) {
                uVar11 = 0xffffffff;
                goto LAB_004cc778;
              }
              iVar12 = iVar12 + 1;
              piVar10 = piVar10 + 1;
            }
          }
          uVar11 = 0;
LAB_004cc778:
          FUN_00407f30(wips_global_mutex);
          if (iVar9 != 0) {
            if (iVar2 == 1) {
              uVar7 = 1;
            }
            else {
              uVar7 = 0;
              if (iVar2 != 2) goto LAB_004cc7a0;
            }
            wips_entry_counter(iVar4,iVar9,uVar7);
          }
LAB_004cc7a0:
          uVar11 = json_object_new_int(uVar11);
          json_object_object_add(param_2,&DAT_00676a24,uVar11);
          FUN_00407df0(iVar4);
          FUN_00407df0(piVar1);
          return;
        }
        if (sensor_err_switch != '\0') {
          pcVar6 = "[SENSOR_ERROR]%s()/%d out of memory\n";
          uVar11 = 0x6d3;
          goto LAB_004cc8b4;
        }
      }
      FUN_00407df0(piVar1);
      goto LAB_004cc638;
    }
    if (sensor_err_switch == '\0') goto LAB_004cc638;
    pcVar6 = "[SENSOR_ERROR]%s()/%d out of memory\n";
    uVar11 = 0x6c0;
  }
  printf(pcVar6,"wips_jcs_callback_wips_event_info_set",uVar11);
LAB_004cc638:
  uVar11 = json_object_new_int(0xffffffff);
  json_object_object_add(param_2,&DAT_00676a24,uVar11);
  return;
}

