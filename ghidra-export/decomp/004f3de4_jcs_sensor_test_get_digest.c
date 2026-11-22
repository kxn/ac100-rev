// func jcs_sensor_test_get_digest @ 004f3de4 size=1532

/* WARNING: Type propagation algorithm not settling */

void jcs_sensor_test_get_digest(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  time_t tVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  short *psVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  short local_ca0 [2];
  undefined4 local_c9c;
  undefined4 local_c98;
  undefined4 local_c94;
  int local_c90 [3];
  ushort local_c84;
  undefined4 local_c80;
  undefined4 local_c7c;
  undefined4 local_c78;
  int local_c74;
  int local_c70;
  short local_c6c;
  undefined1 auStack_c6a [198];
  short local_ba4 [102];
  char acStack_ad8 [32];
  uint local_ab8;
  undefined4 local_800 [500];
  int local_30;
  int local_2c;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d jcs_sensor_test_get_digest ENTER\n",
           "jcs_sensor_test_get_digest",0x15ae);
  }
  local_c90[2] = 0;
  local_c84 = 0;
  local_c90[1] = 0xffffffff;
  memset(local_ba4,0,200);
  memset(&local_c6c,0,200);
  local_c80 = 0;
  local_c7c = 0;
  local_c78 = 0;
  local_c74 = 0;
  local_c70 = 0;
  memset(local_800,0,2000);
  local_c90[0] = 0;
  local_c94 = 0;
  local_c98 = 0;
  local_c9c = 0;
  local_ca0[0] = 0;
  iVar3 = sensor_test_db_get_case_id_list(local_800,local_c90);
  uVar11 = 1;
  if (iVar3 != -1) {
    puVar14 = local_800;
    uVar12 = 0;
    uVar13 = 0;
    puVar15 = puVar14;
    for (iVar3 = 0; iVar3 < local_c90[0]; iVar3 = iVar3 + 1) {
      iVar4 = sensor_test_db_get_case_brief_info(*puVar15,&local_c80);
      if (iVar4 != -1) {
        if ((local_c78._2_1_ != '\0') && (iVar4 = 0, local_c74 != 0)) {
LAB_004f3eec:
          do {
            while( true ) {
              if ((int)(uint)local_c78._2_1_ <= iVar4) goto LAB_004f3f80;
              sVar1 = *(short *)(local_c74 + iVar4 * 4);
              memset(acStack_ad8,0,0x2d8);
              if (99 < uVar13) {
                iVar4 = iVar4 + 1;
                goto LAB_004f3eec;
              }
              if (((int)uVar12 < 0) || (99 < (int)uVar12)) goto LAB_004f3f38;
              iVar5 = apmngr_db_entry_get_by_id(sVar1,acStack_ad8);
              if (iVar5 != -1) break;
              iVar4 = iVar4 + 1;
              if (sensor_test_err_switch == '\0') goto LAB_004f3eec;
              printf("[SENSOR_TEST_ERROR]%s()/%d get sensor entry fail\n",
                     "_sensor_test_add_sensor_to_list",0x137a);
            }
            psVar10 = local_ba4;
            if (uVar13 != 0) {
              iVar5 = 0;
              goto LAB_004f3fbc;
            }
            local_ba4[0] = sVar1;
            if (local_ab8 == 0) {
              local_c6c = sVar1;
            }
            uVar12 = (uint)(local_ab8 == 0);
            uVar13 = 1;
            iVar4 = iVar4 + 1;
          } while( true );
        }
LAB_004f3f80:
        if (local_c70 != 0) {
          FUN_00407df0();
          local_c70 = 0;
        }
        if (local_c74 != 0) {
          FUN_00407df0();
          local_c74 = 0;
        }
      }
      puVar15 = puVar15 + 1;
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d begin to get test_cnt\n","jcs_sensor_test_get_digest",
             0x15e4);
    }
    tVar7 = time((time_t *)0x0);
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d cur_time_stamp=%d\n","jcs_sensor_test_get_digest",0x15e7,
             tVar7);
    }
    iVar4 = 0;
    local_30 = 0;
    iVar3 = 0;
    for (local_2c = 0; local_2c < local_c90[0]; local_2c = local_2c + 1) {
      iVar5 = sensor_test_db_get_case_start_time(*puVar14,&local_c9c,local_ca0);
      uVar11 = local_c9c;
      if (iVar5 != -1) {
        iVar5 = (int)local_ca0[0];
        uVar8 = _sensor_test_calc_total_test_round(local_c9c,iVar5,tVar7);
        if (iVar5 == 0) {
          uVar8 = *puVar14;
        }
        else {
          _sensor_test_calc_time_interval(uVar11,iVar5,tVar7,uVar8,&local_c94,&local_c98);
          uVar8 = *puVar14;
          uVar11 = local_c94;
        }
        iVar5 = sensor_test_db_get_summary_result
                          (uVar8,0xffffffff,0xffffffff,uVar11,tVar7,local_c90 + 1,local_c90 + 2);
        if (iVar5 != -1) {
          iVar3 = iVar3 + ((uint)local_c90[2] >> 0x10);
          local_30 = local_30 + (uint)local_c84;
          iVar4 = iVar4 + (local_c90[2] & 0xffffU);
        }
      }
      puVar14 = puVar14 + 1;
    }
    memset(acStack_ad8,0,0x100);
    snprintf(acStack_ad8,0x100,"%d",iVar3 + local_30 + iVar4);
    uVar11 = json_object_new_string(acStack_ad8);
    json_object_object_add(param_2,"total_test_cnt",uVar11);
    memset(acStack_ad8,0,0x100);
    snprintf(acStack_ad8,0x100,"%d",iVar3);
    uVar11 = json_object_new_string(acStack_ad8);
    json_object_object_add(param_2,"success_cnt",uVar11);
    memset(acStack_ad8,0,0x100);
    snprintf(acStack_ad8,0x100,"%d",iVar4);
    uVar11 = json_object_new_string(acStack_ad8);
    json_object_object_add(param_2,"fail_cnt",uVar11);
    memset(acStack_ad8,0,0x100);
    snprintf(acStack_ad8,0x100,"%d",local_30);
    uVar11 = json_object_new_string(acStack_ad8);
    json_object_object_add(param_2,"slow_cnt",uVar11);
    memset(acStack_ad8,0,0x100);
    snprintf(acStack_ad8,0x100,"%d",uVar13);
    uVar11 = json_object_new_string(acStack_ad8);
    json_object_object_add(param_2,"sensor_cnt",uVar11);
    memset(acStack_ad8,0,0x100);
    snprintf(acStack_ad8,0x100,"%d",uVar12);
    uVar11 = json_object_new_string(acStack_ad8);
    json_object_object_add(param_2,"offline_sensor_cnt",uVar11);
    uVar11 = 0;
  }
  uVar11 = json_object_new_int(uVar11);
  json_object_object_add(param_2,&DAT_00676a24,uVar11);
  return;
  while( true ) {
    iVar5 = iVar5 + 1;
    psVar10 = psVar10 + 1;
    if ((int)uVar13 <= iVar5) break;
LAB_004f3fbc:
    if (*psVar10 == sVar1) {
      uVar6 = local_ab8;
      psVar10 = &local_c6c;
      if (local_ab8 != 0) goto LAB_004f3f38;
      goto LAB_004f4060;
    }
  }
  local_ba4[uVar13] = sVar1;
  uVar13 = uVar13 + 1;
  if (local_ab8 == 0) {
    if (uVar12 == 0) {
LAB_004f4018:
      iVar5 = uVar12 * 2;
      iVar4 = iVar4 + 1;
      uVar12 = uVar12 + 1;
      *(short *)(auStack_c6a + iVar5 + -2) = sVar1;
      goto LAB_004f3eec;
    }
    uVar6 = 0;
    for (puVar9 = auStack_c6a; uVar6 = uVar6 + 1, *(short *)(puVar9 + -2) != sVar1;
        puVar9 = puVar9 + 2) {
      if (uVar6 == uVar12) goto LAB_004f4018;
    }
  }
LAB_004f3f38:
  iVar4 = iVar4 + 1;
  goto LAB_004f3eec;
  while( true ) {
    sVar2 = *psVar10;
    uVar6 = uVar6 + 1;
    psVar10 = psVar10 + 1;
    if (sVar2 == sVar1) break;
LAB_004f4060:
    if (uVar6 == uVar12) goto LAB_004f4018;
  }
  goto LAB_004f3f38;
}

