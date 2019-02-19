Blockly.Blocks['ifttt_webhooks'] = {
	init: function() {
		this.jsonInit({
			"message0": "IFTTT Webhooks trigger %1 Key %2 Event Name %3 Value1 %4 Value2 %5 Value3 %6",
			"args0": [{
				"type": "input_dummy"
			}, {
				"type": "input_value",
				"name": "key",
				"check": "String",
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "event",
				"check": "String",
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "value1",
				"check": [ "Boolean", "Number", "String" ],
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "value2",
				"check": [ "Boolean", "Number", "String" ],
				"align": "RIGHT"
			}, {
				"type": "input_value",
				"name": "value3",
				"check": [ "Boolean", "Number", "String" ],
				"align": "RIGHT"
			}],
			"previousStatement": null,
			"nextStatement": null,
			"colour": 0,
			"tooltip": "Send event to IFTTT webhooks to triggle all service in IFTTT",
			"helpUrl": "https://store.kidbright.info/"
		});
	}
};
