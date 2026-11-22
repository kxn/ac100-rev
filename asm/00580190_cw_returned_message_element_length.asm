; func cw_returned_message_element_length @ 0x00580190 size=0x18
  580190:	10800003 	beqz	a0,0x5801a0
  580194:	00001021 	move	v0,zero
  580198:	90820001 	lbu	v0,1(a0)
  58019c:	24420002 	addiu	v0,v0,2
  5801a0:	03e00008 	jr	ra
  5801a4:	00000000 	nop
