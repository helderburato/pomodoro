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
    <Timer seconds={state.seconds} />
    <button onClick={_ => dispatch(Stop)}> {React.string("Stop")} </button>
    <button onClick={_ => dispatch(Start)}> {React.string("Start")} </button>
    <button onClick={_ => dispatch(Reset)}> {React.string("Reset")} </button>
  </div>;
};
