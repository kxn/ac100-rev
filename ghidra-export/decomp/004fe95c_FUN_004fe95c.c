// func FUN_004fe95c @ 004fe95c size=232

undefined4 FUN_004fe95c(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_90 [128];
  
  memset(acStack_90,0,0x80);
  iVar1 = FUN_00407d60(l_sensor_test_db_ptr,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
    iVar1 = strcmp("testcase_tbl",param_1);
    if (iVar1 == 0) {
      snprintf(acStack_90,0x80,"CREATE UNIQUE INDEX %s_%s ON %s(%s);",param_1,"test_case_id",param_1
               ,"test_case_id");
      FUN_00408530(l_sensor_test_db_ptr,acStack_90);
    }
  }
  else {
    uVar2 = 0xffffffff;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d create table fail\n","_create_table",0xd2);
    }
  }
  return uVar2;
}

