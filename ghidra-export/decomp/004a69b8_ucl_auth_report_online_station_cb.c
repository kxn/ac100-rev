// func ucl_auth_report_online_station_cb @ 004a69b8 size=1248

/* WARNING: Removing unreachable block (ram,0x004a6d4c) */

int ucl_auth_report_online_station_cb(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int in_t9;
  code *pcVar10;
  int local_240;
  undefined1 auStack_23c [304];
  undefined1 auStack_10c [220];
  int local_30;
  int local_2c;
  
  iVar1 = (**(code **)(in_t9 + 0x2b2890))();
  local_240 = 0;
  if (param_1 == 0) {
    piVar2 = *(int **)(in_t9 + 0x2b28f8);
LAB_004a6a8c:
    if (*piVar2 != 0) {
      (**(code **)(in_t9 + 0x2b2f18))
                (*(int *)(in_t9 + 0x2b2840) + -0x1648,*(int *)(in_t9 + 0x2b2840) + -0x9cc,0x26f);
    }
    return -1;
  }
  piVar2 = *(int **)(in_t9 + 0x2b28f8);
  if (param_2 == 0) goto LAB_004a6a8c;
  (**(code **)(in_t9 + 0x2b2df0))(auStack_23c,0,0x205);
  if (iVar1 < 1) {
    return 0;
  }
  iVar3 = ucl_auth_db_is_station_report_switch_enable();
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = ucl_auth_db_get_first_report_finish();
  if (iVar3 == 0) {
    while (iVar1 = (**(code **)(in_t9 + 0x2b2818))(param_1), iVar1 != 0) {
      (**(code **)(in_t9 + 0x2b281c))(iVar1);
      (**(code **)(in_t9 + 0x2b2828))(param_2,iVar1);
    }
    return 0;
  }
  iVar3 = (**(code **)(in_t9 + 0x2b2794))(iVar1 * 0xc4,0x28c);
  iVar4 = (**(code **)(in_t9 + 0x2b2794))(iVar1 * 6,0x28d);
  if (iVar3 == 0) {
    piVar2 = *(int **)(in_t9 + 0x2b28f8);
LAB_004a6cb4:
    if (*piVar2 != 0) {
      (**(code **)(in_t9 + 0x2b2f18))
                (*(int *)(in_t9 + 0x2b2840) + -0x1478,*(int *)(in_t9 + 0x2b2840) + -0x9cc,0x290);
    }
    iVar1 = -1;
    if (iVar3 == 0) goto LAB_004a6cc8;
LAB_004a6d34:
    pcVar10 = *(code **)(in_t9 + 0x2b279c);
  }
  else {
    piVar2 = *(int **)(in_t9 + 0x2b28f8);
    if (iVar4 == 0) goto LAB_004a6cb4;
    (**(code **)(in_t9 + 0x2b2df0))(iVar3,0,iVar1 * 0xc4);
    iVar9 = 0;
    (**(code **)(in_t9 + 0x2b2df0))(iVar4,0,iVar1 * 6);
    iVar5 = (**(code **)(in_t9 + 0x2b2818))(param_1);
    iVar1 = iVar3;
    local_30 = iVar3;
    for (; iVar5 != 0; iVar5 = (**(code **)(in_t9 + 0x2b2884))(iVar5)) {
      (**(code **)(in_t9 + 0x2b2df0))(auStack_23c,0,0x205);
      iVar8 = iVar1 + 100;
      iVar9 = iVar9 + 1;
      (**(code **)(in_t9 + 0x2b2928))(*(undefined4 *)(iVar5 + 0x98),auStack_23c);
      (**(code **)(in_t9 + 0x2b2d30))(iVar1,100,*(int *)(in_t9 + 0x2b2768) + 0x15f0,iVar5 + -0x154);
      (**(code **)(in_t9 + 0x2b2e38))(iVar8,iVar5 + -0x29,6);
      (**(code **)(in_t9 + 0x2b276c))
                (*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10),
                 *(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x18),
                 *(undefined4 *)(iVar5 + 0x1c),iVar1 + 0x6a,0x28,*(int *)(in_t9 + 0x2b2760) + 0x6614
                );
      iVar7 = iVar1 + 0x92;
      iVar1 = iVar1 + 0xc4;
      (**(code **)(in_t9 + 0x2b2d30))(iVar7,0x32,*(int *)(in_t9 + 0x2b2768) + 0x15f0,auStack_10c);
      ucl_auth_db_del_offline_station_by_mac(iVar8);
    }
    iVar1 = -1;
    iVar7 = 0;
    iVar8 = iVar9 / 0x32 + (uint)(iVar9 % 0x32 != 0);
    local_2c = iVar8 + -1;
    for (iVar5 = 0; iVar5 < iVar8; iVar5 = iVar5 + 1) {
      iVar1 = 0x32;
      if (iVar5 == local_2c) {
        iVar1 = iVar9 + iVar8 * -0x32 + 0x32;
      }
      iVar1 = ucl_auth_report_online_station(local_30,iVar1,iVar4 + iVar7 * 6,&local_240);
      local_30 = local_30 + 0x2648;
      if (iVar1 == -1) goto LAB_004a6d34;
      iVar7 = iVar7 + local_240;
    }
    iVar9 = 0;
    iVar5 = iVar4;
LAB_004a6df0:
    if (iVar9 < iVar7) {
      pcVar10 = *(code **)(in_t9 + 0x2b2818);
      iVar8 = param_1;
      while (iVar8 = (*pcVar10)(iVar8), iVar8 != 0) {
        iVar6 = (**(code **)(in_t9 + 0x2b2cd0))(iVar8 + -0x29,iVar5,6);
        if (iVar6 == 0) {
          iVar9 = iVar9 + 1;
          iVar5 = iVar5 + 6;
          (**(code **)(in_t9 + 0x2b281c))();
          (**(code **)(in_t9 + 0x2b2828))(param_2,iVar8);
          goto LAB_004a6df0;
        }
        pcVar10 = *(code **)(in_t9 + 0x2b2884);
      }
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + 6;
      goto LAB_004a6df0;
    }
    pcVar10 = *(code **)(in_t9 + 0x2b279c);
  }
  (*pcVar10)(iVar3);
LAB_004a6cc8:
  if (iVar4 != 0) {
    (**(code **)(in_t9 + 0x2b279c))(iVar4);
  }
  if (iVar1 != -1) {
    return iVar1;
  }
  pcVar10 = *(code **)(in_t9 + 0x2b2818);
  while (iVar1 = (*pcVar10)(param_1), iVar1 != 0) {
    (**(code **)(in_t9 + 0x2b281c))(iVar1);
    (**(code **)(in_t9 + 0x2b2828))(param_2,iVar1);
    pcVar10 = *(code **)(in_t9 + 0x2b2818);
  }
  return 0;
}

