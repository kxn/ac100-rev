// func _sensor_jcs_sensor_manage_status_get @ 004e25c8 size=572

void _sensor_jcs_sensor_manage_status_get(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int iVar10;
  uint uVar11;
  char *local_140 [3];
  char acStack_134 [260];
  int local_30;
  uint local_2c;
  
  local_140[0] = "wait_for_test";
  local_140[1] = "backhaul_testing";
  local_140[2] = "backhaul_test_finished";
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  iVar4 = backhaul_test_suc_sensor_num;
  iVar3 = g_sensor_backhaul_test_state;
  iVar2 = backhaul_test_finished_sensor_num;
  uVar1 = g_sensor_state;
  uVar11 = DAT_00768624;
  iVar10 = sensor_discover_start_timestamp;
  local_2c = 0;
  local_30 = 0;
  if (g_sensor_state != 0) {
    uVar9 = FUN_00407e70();
    uVar7 = uVar11 + 600;
    local_2c = uVar7 - (int)uVar9;
    local_30 = (((uint)(uVar7 < uVar11) + iVar10) - (int)((ulonglong)uVar9 >> 0x20)) -
               (uint)(uVar7 < local_2c);
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  if (uVar1 < 3) {
    uVar8 = json_object_new_string((&PTR_DAT_006b2110)[uVar1]);
  }
  else {
    uVar8 = 0xfffffff5;
    if (uVar1 != 3) goto LAB_004e2688;
    if (iVar3 == 2) {
      pcVar6 = "backhaul_test_finished";
      if (iVar2 != iVar4) {
        if (iVar4 == 0) {
          pcVar6 = "backhaul_test_failed";
        }
        else {
          pcVar6 = "backhaul_test_part_failed";
        }
      }
    }
    else {
      pcVar6 = local_140[iVar3];
    }
    uVar8 = json_object_new_string(pcVar6);
  }
  json_object_object_add(param_2,"status",uVar8);
  uVar8 = 0;
LAB_004e2688:
  memset(acStack_134,0,0x100);
  iVar10 = local_30;
  uVar11 = local_2c;
  snprintf(acStack_134,0x100,"%lld");
  uVar5 = json_object_new_string(acStack_134);
  json_object_object_add(param_2,"remain_time",uVar5);
  memset(acStack_134,0,0x100);
  snprintf(acStack_134,0x100,"%d",uVar8,iVar10,uVar11);
  uVar8 = json_object_new_string(acStack_134);
  json_object_object_add(param_2,&DAT_00676a24,uVar8);
  return;
}

