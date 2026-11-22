// func sensor_test_db_group_id_delete @ 005049bc size=616

undefined4 sensor_test_db_group_id_delete(short *param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  short *psVar9;
  short *psVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  short local_828 [1024];
  
  memset(local_828,0,0x800);
  uVar4 = 0xffffffff;
  if (((param_1 != (short *)0x0) && (0 < param_2)) && (param_2 < 0x401)) {
    uVar14 = 0;
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
LAB_00504a34:
    if (uVar14 < g_sensor_test_case_num_max) {
      iVar13 = uVar14 * 4;
      if ((*(int *)(l_sensor_test_case_list + iVar13) != 0) &&
         (iVar11 = *(int *)(*(int *)(l_sensor_test_case_list + iVar13) + 4), iVar11 != 0)) {
        memset(local_828,0,0x800);
        uVar12 = 0;
        bVar1 = *(byte *)(iVar11 + 9);
        bVar3 = false;
        iVar8 = 0;
        psVar6 = param_1;
        do {
          iVar5 = 0;
          while (iVar5 < (int)(uint)bVar1) {
            sVar2 = *(short *)(*(int *)(iVar11 + 0x30) + iVar5 * 2);
            if (*psVar6 == sVar2) {
              bVar3 = true;
              iVar5 = iVar5 + 1;
            }
            else {
              psVar9 = local_828 + uVar12;
              uVar12 = uVar12 + 1 & 0xffff;
              iVar5 = iVar5 + 1;
              *psVar9 = sVar2;
            }
          }
          iVar8 = iVar8 + 1;
          psVar6 = psVar6 + 1;
        } while (iVar8 != param_2);
        if (bVar3) {
          psVar6 = (short *)FUN_00408450(uVar12 << 1,0x12dd);
          if (psVar6 == (short *)0x0) {
            if (sensor_test_err_switch == '\0') {
              uVar14 = uVar14 + 1;
            }
            else {
              printf("[SENSOR_TEST_ERROR]%s()/%d new_group_list mem malloc fail\n",
                     "sensor_test_db_group_id_delete",0x12e0);
              uVar14 = uVar14 + 1;
            }
          }
          else {
            memset(psVar6,0,uVar12 << 1);
            psVar9 = psVar6;
            psVar10 = local_828;
            for (iVar11 = 0; iVar11 < (int)uVar12; iVar11 = iVar11 + 1) {
              sVar2 = *psVar10;
              psVar10 = psVar10 + 1;
              *psVar9 = sVar2;
              psVar9 = psVar9 + 1;
            }
            piVar7 = (int *)(l_sensor_test_case_list + iVar13);
            *(char *)(*(int *)(*piVar7 + 4) + 9) = (char)uVar12;
            if (*(int *)(*(int *)(*piVar7 + 4) + 0x30) != 0) {
              FUN_00407df0();
              *(undefined4 *)(*(int *)(*(int *)(l_sensor_test_case_list + iVar13) + 4) + 0x30) = 0;
            }
            piVar7 = (int *)(l_sensor_test_case_list + iVar13);
            *(short **)(*(int *)(*piVar7 + 4) + 0x30) = psVar6;
            uVar4 = _sensor_test_db_deep_copy_test_case(*piVar7);
            sensor_test_db_msg_send(2,uVar4);
            uVar14 = uVar14 + 1;
          }
          goto LAB_00504a34;
        }
      }
      uVar14 = uVar14 + 1;
      goto LAB_00504a34;
    }
    FUN_00407f30(l_sensor_test_db_mutex);
    uVar4 = 0;
  }
  return uVar4;
}

