// func jcs_test_callback_get @ 00529050 size=60

void jcs_test_callback_get(void)

{
  int in_t9;
  
  if (**(int **)(in_t9 + 0x2304bc) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00529084. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(in_t9 + 0x230880))
              (*(int *)(in_t9 + 0x2300d8) + 0x4fbc,*(int *)(in_t9 + 0x2300d8) + 0x53e8,0x26f);
    return;
  }
  return;
}

