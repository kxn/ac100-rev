// func jcs_test_case @ 005296fc size=124

void jcs_test_case(void)

{
  jcs_callback_register("example",0,jcs_test_callback_add);
  jcs_callback_register("example",1,jcs_test_callback_del);
  jcs_callback_register("example",3,jcs_test_callback_get);
  return;
}

