Blockly.JavaScript['ifttt_webhooks'] = function(block) {
	var value_key = Blockly.JavaScript.valueToCode(block, 'key', Blockly.JavaScript.ORDER_ATOMIC);
	var value_event = Blockly.JavaScript.valueToCode(block, 'event', Blockly.JavaScript.ORDER_ATOMIC);
	var value_value1 = Blockly.JavaScript.valueToCode(block, 'value1', Blockly.JavaScript.ORDER_ATOMIC);
	var value_value2 = Blockly.JavaScript.valueToCode(block, 'value2', Blockly.JavaScript.ORDER_ATOMIC);
	var value_value3 = Blockly.JavaScript.valueToCode(block, 'value3', Blockly.JavaScript.ORDER_ATOMIC);
	var code = 'DEV_IO.IFTTT().set(1, ' + value_value1 + '); DEV_IO.IFTTT().set(2, ' + value_value2 + '); DEV_IO.IFTTT().set(3, ' + value_value3 + '); DEV_IO.IFTTT().send(' + value_key + ', ' + value_event + ');\n';
	return code;
};
