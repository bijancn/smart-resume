// ReactDOMRe.renderToElementWithId(
//   <Component1 message="Hello! Click this text." />,
//   "index1",
// );

let filterFunc: 'a => option('a) = x => Some(x);

let data: DataModel.resumeData = {
  name: {
    firstName: "Bijan",
    middleName: "Alain",
    lastName: "Chokoufe Nejad",
  },
  headline: "Scala Developer at enfore - PhD Physics",
  location: "Hamburg",
  socials: [],
  summary: {
    content: "After my PhD in theoretical physics, I followed my passion for functional programming and clean code. I like to find simple solutions to complex problems.
    Also: I'm a Prachtbursche! ;)
    ",
  },
  work: [
    {
      startDate: {
        repr: "September 2009",
      },
      endDate: {
        repr: "Present",
      },
      company: "enfore",
      website: "???",
      position: "Software Engineer",
      summary: "doing stuff",
      highlights: ["this", "that", "more"],
    },
  ],
  education: [],
  publications: [],
  skills: [],
  languages: [],
};

let parseDataFromJSON = () => {
  data;
};

type theme =
  | Lean
  | Clean
  | Fancy;
let chosenTheme = Lean;
let render = () =>
  ReactDOMRe.renderToElementWithId(
    <Main data={parseDataFromJSON()} filterFunc />,
    "main",
  );

switch (chosenTheme) {
| Lean => render()
| Clean => render()
| Fancy => render()
};