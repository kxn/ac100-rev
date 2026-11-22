// func _sensor_test_db_get_idx_of_serindex @ 004fdb3c size=536

int _sensor_test_db_get_idx_of_serindex(ushort *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_db_get_idx_of_serindex ENTER\n",
           "_sensor_test_db_get_idx_of_serindex",0x661);
  }
  if (((param_1 == (ushort *)0x0) || ((int)param_2 < 0)) || (8 < (int)param_2)) {
    iVar1 = -1;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d input invalid\n","_sensor_test_db_get_idx_of_serindex",
             0x667);
    }
  }
  else {
    iVar1 = -1;
    if (((int)(uint)*param_1 >> (param_2 & 0x1f) & 1U) != 0) {
      if (param_2 == 4) {
        iVar2 = 0;
        iVar1 = **(int **)(param_1 + 8);
        if (iVar1 == 0) {
          iVar1 = -1;
        }
        else {
          for (; iVar2 < iVar1; iVar2 = iVar2 + 1) {
            if (*(ushort *)((*(int **)(param_1 + 8))[1] + iVar2 * 0x28c + 0x28a) == param_3) {
              return iVar2;
            }
          }
          iVar1 = -1;
        }
      }
      else if ((int)param_2 < 5) {
        if (param_2 == 2) {
          iVar2 = 0;
          iVar1 = **(int **)(param_1 + 4);
          if (iVar1 == 0) {
            iVar1 = -1;
          }
          else {
            for (; iVar2 < iVar1; iVar2 = iVar2 + 1) {
              if (*(ushort *)((*(int **)(param_1 + 4))[1] + iVar2 * 0x102 + 0x100) == param_3) {
                return iVar2;
              }
            }
            iVar1 = -1;
          }
        }
        else {
          iVar1 = 0;
        }
      }
      else if (param_2 == 5) {
        iVar2 = 0;
        iVar1 = **(int **)(param_1 + 10);
        if (iVar1 == 0) {
          iVar1 = -1;
        }
        else {
          for (; iVar2 < iVar1; iVar2 = iVar2 + 1) {
            if (*(ushort *)((*(int **)(param_1 + 10))[1] + iVar2 * 0x104 + 0x102) == param_3) {
              return iVar2;
            }
          }
          iVar1 = -1;
        }
      }
      else {
        iVar1 = 0;
        if (param_2 == 6) {
          iVar2 = **(int **)(param_1 + 0xc);
          if (iVar2 == 0) {
            iVar1 = -1;
          }
          else {
            for (; iVar1 < iVar2; iVar1 = iVar1 + 1) {
              if (*(ushort *)((*(int **)(param_1 + 0xc))[1] + iVar1 * 0xa8e + 0xa8c) == param_3) {
                return iVar1;
              }
            }
            iVar1 = -1;
          }
        }
      }
    }
  }
  return iVar1;
}

