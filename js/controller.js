(function() {

    var app = angular.module('store', ['angularPaho']);

    app.controller('test', [ '$scope', 'MqttClient', function($scope, MqttClient) {

        var ip = "10.0.0.77";
        var port = "9001";
        var id = "bcst";

        $scope.oklar = "ok";

 

        $scope.temp = "";


        $scope.state = 'Switch On';

        MqttClient.init(ip, port, id);


        MqttClient.connect({onSuccess: successCallback});

	$scope.message = MqttClient.data;



        $scope.doit = function() {
            console.log("click effect")
            if ($scope.state == 'Switch On'){
                $scope.state = "Switch Off";
                message = new Paho.MQTT.Message('0');
                message.destinationName = "lamp";
                MqttClient.send(message);
		//$scope.message = MqttClient.data;
		

            }
            else{
                $scope.state = "Switch On";
                message = new Paho.MQTT.Message('1');
                message.destinationName = "lamp";
                MqttClient.send(message);
            }

        }

        //MqttClient.onMessageArrived= onArrived;
        function successCallback() {
            console.log("Hooya");
            $scope.oklar="Yes"
            MqttClient.subscribe('lamp');
            //message = new Paho.MQTT.Message("1");
            //message.destinationName = "lamp";
           //MqttClient.send(message);
        }


    }]);


})();
