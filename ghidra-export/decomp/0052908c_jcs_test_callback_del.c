// func jcs_test_callback_del @ 0052908c size=60

void jcs_test_callback_del(void)

{
  int in_t9;
  
  if (**(int **)(in_t9 + 0x230480) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005290c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(in_t9 + 0x230844))
              (*(int *)(in_t9 + 0x23009c) + 0x4fe0,*(int *)(in_t9 + 0x23009c) + 0x5400,0x27a);
    return;
  }
  return;
}

