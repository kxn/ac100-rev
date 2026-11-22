// func systime_jcs_callback_systime_set @ 00666380 size=492

void systime_jcs_callback_systime_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (((param_1 == 0) || (param_2 == 0)) || (systime_register_list == 0)) {
    if (g_systime_error != 0) {
      printf("[SYSTIME_ERROR] %32s() %05d: inputs error.\r\n","systime_jcs_callback_systime_set",
             0x47);
      return;
    }
    return;
  }
  if (g_systime_debug != 0) {
    printf("[SYSTIME_DEBUG] %32s() %05d: systime handle start.\r\n",
           "systime_jcs_callback_systime_set",0x4b);
  }
  iVar1 = FUN_004081b0(systime_register_list);
  if (iVar1 == 0) {
LAB_0066643c:
    if (g_systime_debug != 0) {
      printf("[SYSTIME_DEBUG] %32s() %05d: systime handle end.\r\n",
             "systime_jcs_callback_systime_set",100);
    }
    uVar3 = json_object_new_int(1);
    json_object_object_add(param_2,&DAT_00676a24,uVar3);
    return;
  }
  pcVar4 = *(code **)(iVar1 + 0x90);
  do {
    if (pcVar4 != (code *)0x0) {
      if ((*(int **)(iVar1 + 0x94) == (int *)0x0) || (**(int **)(iVar1 + 0x94) == 0)) {
        iVar2 = (*pcVar4)(0);
        if ((iVar2 == -1) && (g_systime_error != 0)) {
          uVar3 = 0x5e;
          goto LAB_006664bc;
        }
      }
      else {
        iVar2 = (*pcVar4)();
        if ((iVar2 == -1) && (uVar3 = 0x57, g_systime_error != 0)) {
LAB_006664bc:
          printf("[SYSTIME_ERROR] %32s() %05d: %s block occured some error.\r\n",
                 "systime_jcs_callback_systime_set",uVar3,iVar1 + 0xc);
        }
      }
    }
    iVar1 = FUN_00408680(iVar1);
    if (iVar1 == 0) goto LAB_0066643c;
    pcVar4 = *(code **)(iVar1 + 0x90);
  } while( true );
}

