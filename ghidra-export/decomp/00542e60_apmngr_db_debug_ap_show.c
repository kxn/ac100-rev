// func apmngr_db_debug_ap_show @ 00542e60 size=1

void apmngr_db_debug_ap_show(char param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  puts("Show data in MEMORY.");
  printf("=============AP Entry ((%d+%d)/(%d+%d)))================\n",(uint)g_apmngr_active_ap_num,
         (uint)g_apmngr_active_sensor_num,(uint)g_apmngr_ap_num,(uint)g_apmngr_sensor_num);
  printf(
        "  ID (type, link, role )|GID|     Entry-Name     |       MAC       |      Hardware      |         Soft Ver        | Status|  LED  | led_sent |Flag |Timer_id|Timer_time"
        );
  if (iVar4 == 1) {
    printf("\nOptions..");
  }
  uVar3 = 0;
  putchar(10);
  while ((int)uVar3 < apmngr_ap_num_max) {
    iVar1 = g_apmngr_entry_array + uVar3 * 0x2d8;
    if (*(int *)(iVar1 + 0x1c) == 0) {
      uVar3 = uVar3 + 1 & 0xffff;
    }
    else {
      apmngr_debug_ap_print(iVar1,iVar4);
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  uVar3 = 50000;
  while ((int)uVar3 < apmngr_sensor_num_max + 50000) {
    uVar2 = uVar3;
    if (49999 < uVar3) {
      uVar2 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    iVar1 = g_apmngr_entry_array + uVar2 * 0x2d8;
    if (*(int *)(iVar1 + 0x1c) == 0) {
      uVar3 = uVar3 + 1 & 0xffff;
    }
    else {
      apmngr_debug_ap_print(iVar1,iVar4);
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  return;
}

