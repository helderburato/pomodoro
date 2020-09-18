open Utils;
open State;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  // It's the same of React.useEffect((), []);
  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div>
    <button onClick={_ => dispatch(TogglePhase)}>
      {s("Switch timer")}
    </button>
    <Timer seconds={state.seconds} />
    <button onClick={_ => dispatch(Stop)}> {React.string("Stop")} </button>
    <button onClick={_ => dispatch(Start)}> {React.string("Start")} </button>
    <button onClick={_ => dispatch(Reset)}> {React.string("Reset")} </button>
    <FormInputTime
      phase="Work"
      value={state.workTime}
      onChange={e => dispatch(SetTime(Work, e))}
    />
    <FormInputTime
      phase="Break"
      value={state.playTime}
      onChange={e => dispatch(SetTime(Play, e))}
    />
  </div>;
};
