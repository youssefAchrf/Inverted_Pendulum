classdef DigitalWrite_raspi < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.Propagates ...
        & matlab.system.mixin.CustomIcon
    %
    % Set the logical state of a digital output pin.
    %
    
    % Copyright 2014 The MathWorks, Inc.
    %#codegen
    %#ok<*EMCA>
    
    properties (Nontunable)
        Pin = 14
    end
    
    properties (Constant, Hidden)
        AvailablePin = [4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27];
        OUTPUT = 1;
        INPUT  = 0;
    end
    
    methods
        % Constructor
        function obj = DigitalWrite_raspi(varargin)
            coder.allowpcode('plain');
            
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
        
        function set.Pin(obj,value)
            coder.extrinsic('sprintf') % Do not generate code for sprintf
            validateattributes(value,...
                {'numeric'},...
                {'real', 'positive', 'integer','scalar'},...
                '', ...
                'Pin');
            assert(any(value == obj.AvailablePin), ...
                'Invalid value for Pin. Pin must be one of the following: %s', ...
                sprintf('%d ', obj.AvailablePin));
            obj.Pin = value;
        end
    end
    
    methods (Access=protected)
        function setupImpl(obj)
            if coder.target('Rtw')
                coder.cinclude('digitalio_raspi.h');
                coder.ceval('digitalIOSetup', obj.Pin, obj.OUTPUT);
            end
        end
        
        function stepImpl(obj,u)
            if coder.target('Rtw')
                coder.ceval('writeDigitalPin', obj.Pin, u);
            end
        end
        
        function releaseImpl(obj) %#ok<MANU>
        end
    end
    
    methods (Access=protected)
        %% Define input properties
        function num = getNumInputsImpl(~)
            num = 1;
        end
        
        function num = getNumOutputsImpl(~)
            num = 0;
        end
        
        function flag = isInputSizeLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputFixedSizeImpl(~,~)
            varargout{1} = true;
        end
        
        function flag = isInputComplexityLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputComplexImpl(~)
            varargout{1} = false;
        end
        
        function validateInputsImpl(~, u)
            if isempty(coder.target)
                % Run this always in Simulation
                validateattributes(u,{'logical','double'},{'scalar','binary'},'','u');
            end
        end
        
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'Digital Write';
        end
    end
    
    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end
    
    methods (Static)
        function name = getDescriptiveName()
            name = 'Digital Write';
        end
        
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                rootDir = fullfile(fileparts(mfilename('fullpath')),'..','src');
                buildInfo.addIncludePaths(rootDir);
                buildInfo.addIncludeFiles('digitalio_raspi.h');
                buildInfo.addSourceFiles('digitalio_raspi.c',rootDir);
                buildInfo.addLinkFlags({'-lwiringPi'});
            end
        end
    end
end
