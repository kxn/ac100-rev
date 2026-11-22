// func _alarm_timeout @ 0043b0e0 size=36

void _alarm_timeout(void)

{
  FUN_00407df0(g_wechat_config);
                    /* WARNING: Subroutine does not return */
  g_wechat_config = 0;
  exit(1);
}

