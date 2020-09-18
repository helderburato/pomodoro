type phase =
  | Work
  | Play;

type action =
  | Start
  | Stop
  | Reset
  | Tick
  | TogglePhase
  | SetTime(phase, int);

type state = {
  seconds: int,
  isTicking: bool,
  workTime: int,
  playTime: int,
  currentPhase: phase,
};

let initialState = {
  seconds: 0,
  isTicking: false,
  workTime: 25,
  playTime: 5,
  currentPhase: Play,
};

let reducer = (state, action) =>
  switch (action) {
  | Start => {...state, isTicking: true}
  | Stop => {...state, isTicking: false}
  | Tick =>
    state.isTicking && state.seconds > 0
      ? {...state, seconds: state.seconds - 1} : state
  | Reset =>
    switch (state.currentPhase) {
    | Work => {...state, seconds: state.workTime * 60}
    | Play => {...state, seconds: state.playTime * 60}
    }
  | SetTime(phase, number) =>
    switch (phase) {
    | Work => {...state, workTime: number}
    | Play => {...state, playTime: number}
    }
  | TogglePhase =>
    switch (state.currentPhase) {
    | Work => {
        ...state,
        seconds: state.playTime * 60,
        currentPhase: Play,
        isTicking: true,
      }
    | Play => {
        ...state,
        seconds: state.workTime * 60,
        currentPhase: Work,
        isTicking: true,
      }
    }
  };
